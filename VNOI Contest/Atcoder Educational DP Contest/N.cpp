#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 405;

int n;
int a[N];
int s[N];
int f[N][N];

int dp(int l, int r){
    if(f[l][r] != -1) return f[l][r];
    if(l == r) return 0;
    if(l + 1 == r) return a[l] + a[r];
    int res = 1e18;
    for(int i = l; i < r; i++){
        res = min(res, dp(l, i) + dp(i + 1, r) + s[r] - s[l - 1]);
    }
    return f[l][r] = res;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            f[i][j] = -1;
        }
    }
    cout << dp(1, n);
}
