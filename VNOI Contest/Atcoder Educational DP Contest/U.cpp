#include<bits/stdc++.h>
using namespace std;

#define int long long
int n;
int a[16][16];
int dp[1 << 16];
int val[1 << 16];

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < (1 << n); i++){
        for(int j1 = 0; j1 < n; j1++){
            if(i >> j1 & 1)
            for(int j2 = j1 + 1; j2 < n; j2++){
                if(i >> j2 & 1)
                val[i] += a[j1][j2];
            }
        }
    }

    /// Iterating through all masks with their submasks. Complexity O(3^n)
    for(int i = 0; i < (1 << n); i++){
        for(int j = i; j; j = (j - 1) & i){
            dp[i] = max(dp[i], dp[i ^ j] + val[j]);
        }
    }
    cout << dp[(1 << n) - 1];
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
//https://oj.vnoi.info/problem/atcoder_dp_u
