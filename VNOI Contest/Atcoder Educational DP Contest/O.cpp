#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> II;
typedef pair<II, int> III;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 20 + 5;

int n;
int a[N][N];

int dp[1 << 21];
vector<int> b[N];

int32_t main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}

	for(int i = 0; i < (1 << n); i++){
		int val = __builtin_popcount(i);
		b[val].push_back(i);
	}

    dp[0] = 1;
	for(int i = 0; i < n; i++){
		for(int mask: b[i]){
			for(int j = 0; j < n; j++){
                //The j_th woman have been paired with the man before
                //or not compatible with the i_th man
				if(mask >> j & 1 || !a[i + 1][j + 1]) continue;

                //The i_th man is paired with the j_th woman
				int on = mask | (1 << j);
				dp[on] += dp[mask];
				dp[on] %= MOD;
			}
		}
	}

	cout << dp[(1 << n) - 1];
}
