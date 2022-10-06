#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, m;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    int l = 1, r = 1e9;
    int right = 1;
    while(l <= r){
        int mid = (l + r) / 2;
        int sum = n * (2 * mid - n + 1) / 2;
        if(sum <= m){
            right = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    if(n * (2 * right - n + 1) / 2 == m){
        cout << right - n + 1 << " " << right;
        return 0;
    }
    cout << right - n + 1 << " " << right + 1;

}
