#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;
const int N = 300 + 5;

int n, k;
int a[N];
int f[N][N][N];

int dp(int l, int r, int k){
	if(k == 0) return 0;

	if(r - l + 1 < 2 * k) return -INF;

	if(f[l][r][k] != -1) return f[l][r][k];
	int res = 0;

	res = max(res, abs(a[l] - a[l + 1]) + dp(l + 2, r, k - 1));

	res = max(res, abs(a[r] - a[r - 1]) + dp(l, r - 2, k - 1));

	res = max(res, abs(a[l] - a[r]) + dp(l + 1, r - 1, k - 1));

	res = max(res, dp(l + 1, r, k));

	res = max(res, dp(l, r - 1, k));

	return f[l][r][k] = res;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			for(int t = 0; t <= k; t++){
				f[i][j][t] = -1;
			}
		}
	}

	cout << dp(1, n, k) << '\n';
	

}