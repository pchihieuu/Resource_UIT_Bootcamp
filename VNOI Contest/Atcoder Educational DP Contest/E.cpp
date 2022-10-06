#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, w;
int a[105][2];
int f[100005];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> w;
    for(int i = 1; i <= n; i++){
        cin >> a[i][0] >> a[i][1];
    }

    for(int i = 1; i <= 100000; i++){
        f[i] = 1e18;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 100000; j >= 0; j--){
            if(f[j] == 1e18) continue;
            f[j + a[i][1]] = min(f[j + a[i][1]], f[j] + a[i][0]);
        }
    }

    int res = 0;
    for(int i = 0; i <= 100000; i++){
        if(f[i] <= w){
            res = i;
        }
    }

    cout << res;
}
