#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int Pow(int a, int b){
    if(b == 0) return 1;
    if(b == 1) return a;
    int c = Pow(a, b / 2);
    c = (c * c) % MOD;
    if(b & 1) c = (c * a) % MOD;
    return c;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    cout << Pow(3, n - 1);
}
