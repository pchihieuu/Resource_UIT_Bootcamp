#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int N = 105;
const int K = 1e5 + 5;

int n, k;
int a[N];
int dp[N][K];

int s(int i, int l, int r){
    if(l < 1) return dp[i][r];
    return (dp[i][r] - dp[i][l - 1] + MOD * MOD) % MOD;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    if(k == 0){
        cout << 1;
        return 0;
    }

    for(int i = 0; i <= k; i++){
        if(i <= a[1]) dp[1][i] = 1;
        if(i > 0) dp[1][i] += dp[1][i - 1];
    }
    int sumA = a[1];
    for(int i = 2; i <= n; i++){
        //cout << i << ": ";
        sumA += a[i];
        dp[i][0] = 1;
        for(int j = 1; j <= k; j++){
            if(sumA < j) break;
            //cout << s(i - 1, j - a[i], j) << " ";
            dp[i][j] += s(i - 1, j - a[i], j);
            dp[i][j] %= MOD;
        }
        for(int j = 1; j <= k; j++){
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
        //cout << endl;
    }

    cout << (dp[n][k] - dp[n][k - 1] + MOD * MOD) % MOD;
}
