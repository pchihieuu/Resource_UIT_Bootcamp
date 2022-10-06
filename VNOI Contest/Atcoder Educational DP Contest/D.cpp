#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;

int n, w;
int a[N][2], f[N];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> w;
    for(int i = 1; i <= n; i++){
        cin >> a[i][0] >> a[i][1];
    }
    f[0] = 0;
    for(int i = 1; i <= w; i++){
        f[i] = -1e18;
    }
    for(int i = 1; i <= n; i++){
        for(int j = w; j >= 1; j--){
            if(j - a[i][0] < 0) break;
            f[j] = max(f[j], f[j - a[i][0]] + a[i][1]);
        }
    }

    int res = 0;
    for(int i = 0; i <= w; i++){
        res = max(res, f[i]);
    }

    cout << res;
}
