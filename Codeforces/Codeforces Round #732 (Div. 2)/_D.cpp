#include<bits/stdc++.h>
using namespace std;

#define int int64_t

const int N = 1e5 + 5;
const int MOD = 998244353;

int n;
int a[N], x[N][2], f[N][2][2];

void read(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		char x;
		cin >> x;
		a[i] = x - '0';
	}
}


void process(){
	if(n <= 2){
		cout << 1 << '\n';
		return;
	}

	x[n][a[n]] = 1;
	x[n][a[n] ^ 1] = 0;
	x[n - 1][a[n - 1]] = 1;
	x[n - 1][a[n - 1] ^ 1] = 0;

	for(int i = n - 2; i >= 1; i--){
		if(a[i] == 0){
			x[i][0] = 1;
			if(x[i + 1][1] && x[i + 2][1]){
				x[i][1] = 1;
			}
		}
		else{
			x[i][1] = 1;
			if(x[i + 1][1] && x[i + 2][0]){
				x[i][0] = 1;
			}
		}
	}
	f[2][a[1]][a[2]] = 1;

	for(int i = 3; i <= n; i++){
		for(int t1 = 0; t1 <= 1; t1++){
			for(int t2 = 0; t2 <= 1; t2++){
				for(int t3 = 0; t3 <= 1; t3++){
					if(x[i][t3] == 0) continue;
					if(f[i - 1][t1][t2] == 0) continue;
					f[i][t2][t3] += f[i - 1][t1][t2];
					f[i][t2][t3] %= MOD;
					if(t1 == 0 && t2 && t3) f[i][1][0] += 1, f[i][1][0] %= MOD;
					if(t1 && t2 && t3 == 0) f[i][1][1] += 1, f[i][1][1] %= MOD;
				}
			}
		}
		cout << endl;
		for(int t1 = 0; t1 <= 1; t1++){
			for(int t2 = 0; t2 <= 1; t2++){
				if(f[i][t1][t2]) cout << t1 << t2 << " = " << f[i][t1][t2] << endl;
			}
		}
	}

	int res = 0;
	for(int i = 0; i <= 1; i++){
		for(int j = 0; j <= 1; j++){
			res += f[n][i][j];
			res %= MOD;
		}
	}

	cout << res << '\n';
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int Test;
	cin >> Test;
	for(int i = 1; i <= Test; i++){
		read();
		process();
	}
}
/*
1
4
0110


0110

01 = 1
all = 0

00 00 = 0
00 10 = 0
01 00 = 0
01 10 = 0
10 01 = 0
10 11 = 0
11 01 = 1 => 10 = 1
11 11 = 0

00 00 = 0
00 10 = 1
01 = ?
10 01 = 0
10 11 = 1 => 11 = 1





*/