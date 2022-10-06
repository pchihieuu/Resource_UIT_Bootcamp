#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, m;

int f[30 + 5][1 << 5];

int check(int t1, int t2){
	for(int i = 0; i < m - 1; i++){
		if(((t1 >> i & 1) && (t2 >> i & 1) && (t1 >> (i + 1) & 1) && (t2 >> (i + 1) & 1))
			|| (!(t1 >> i & 1) && !(t2 >> i & 1) && !(t1 >> (i + 1) & 1) && !(t2 >> (i + 1) & 1))){
			return 0;
		}
	}
	return 1;
}

void solve(){
	cin >> n >> m;
	int a = min(n, m), b = max(n, m);
	n = b, m = a;

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < (1 << m); j++){
			f[i][j] = 0;
		}
	}

	for(int j = 0; j < (1 << m); j++){
		f[1][j] = 1;
	}

	for(int i = 2; i <= n; i++){
		for(int t1 = 0; t1 < (1 << m); t1++){
			for(int t2 = 0; t2 < (1 << m); t2++){
				if(check(t1, t2)){
					f[i][t2] += f[i - 1][t1];
				}
			}
		}
	}

	int res = 0;
	for(int j = 0; j < (1 << m); j++){
		res += f[n][j];
	}

	cout << res << '\n';
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		solve();
	}


}