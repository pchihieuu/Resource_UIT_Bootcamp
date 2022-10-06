#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a, res;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    a.resize(n);
    res.resize(n);
    for(int &i: a) cin >> i;
    res[0] = 0;
    res[1] = abs(a[1] - a[0]);
    for(int i = 2; i < n; i++){
        res[i] = min(res[i - 1] + abs(a[i] - a[i - 1]), res[i - 2] + abs(a[i] - a[i - 2]));
    }
    cout << res[n - 1];
}
