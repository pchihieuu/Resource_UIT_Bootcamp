#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 16 + 5;

int n;
int a[N][N];
int f[N][1 << 16];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < (1 << n); j++){
			f[i][j] = INF;
		}
	}

	for(int i = 0; i < n; i++){
		f[i + 1][1 << i] = 0;
	}

	for(int i = 0; i < (1 << n); i++){
		for(int t1 = 0; t1 < n; t1++){
			if(i >> t1 & 1) continue;
			int onbit = i | (1 << t1);
			for(int t2 = 0; t2 < n; t2++){
				if((i >> t2 & 1) == 0) continue;
				f[t1 + 1][onbit] = min(f[t1 + 1][onbit], f[t2 + 1][i] + a[t2 + 1][t1 + 1]);
			}
		}
	}
	
	int res = INF;
	for(int i = 0; i < n; i++){
		res = min(res, f[i + 1][(1 << n) - 1]);
	}

	cout << res;
}