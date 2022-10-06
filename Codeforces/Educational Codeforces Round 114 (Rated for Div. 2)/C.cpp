#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;

int n, m;
int a[N];
int x, y;

void solve(){
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);

    cin >> m;
    while(m--){
        cin >> x >> y;
        if(a[1] >= x){
            cout << max(0ll, y - (sum - a[1])) << '\n';
            continue;
        }
        if(a[n] <= x){
            cout << x - a[n] + max(0ll, y - (sum - a[n])) << '\n';
            continue;
        }

        int l = 1, r = n;
        r = lower_bound(a + 1, a + n + 1, x) - a;
        l = r - 1;

        cout << min(max(0ll, y - (sum - a[r])), x - a[l] + max(0ll, y - (sum - a[l]))) << '\n';

    }

}


int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();

}
