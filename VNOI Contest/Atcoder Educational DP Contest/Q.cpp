#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;

int n;
int bit[N];
int h[N], a[N];

void update(int x, int val){
    for(; x < N; x += x&-x){
        bit[x] = max(bit[x], val);
    }
}

int get(int x){
    int val = 0;
    for(; x >= 1; x -= x&-x){
        val = max(val, bit[x]);
    }
    return val;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++) cin >> a[i];

    int res = 0;
    for(int i = 1; i <= n; i++){
        int val = get(h[i]);
        res = max(res, val + a[i]);
        update(h[i], val + a[i]);
    }

    cout << res;
}
