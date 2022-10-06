#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a, res;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    a.resize(n);
    res.resize(n);
    for(int &i: a) cin >> i;
    res[0] = 0;
    for(int i = 1; i < n; i++){
        res[i] = 1e9;
        for(int j = i - 1; j >= max(0, i - k); j--)
            res[i] = min(res[i], res[j] + abs(a[i] - a[j]));
    }
    cout << res[n - 1];
}
