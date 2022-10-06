#include<bits/stdc++.h>
using namespace std;

#define int long long

int n;
int a[3005];
int f[3005][3005];

int dp(int l, int r, int block){
    if(f[l][r] != 1e18) return f[l][r];
    if(block == 1){
        if(l == r) return a[l];
        //left
        int val1 = a[l] + dp(l + 1, r, block ^ 1);
        //right
        int val2 = a[r] + dp(l, r - 1, block ^ 1);
        return f[l][r] = max(val1, val2);
    }
    else{
        if(l == r) return -a[l];
        //left
        int val1 = -a[l] + dp(l + 1, r, block ^ 1);
        //right
        int val2 = -a[r] + dp(l, r - 1, block ^ 1);
        return f[l][r] = min(val1, val2);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            f[i][j] = 1e18;
        }
    }
    cout << dp(1, n, 1);
}
