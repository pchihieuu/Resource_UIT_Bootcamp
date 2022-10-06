#include<bits/stdc++.h>
using namespace std;

#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ld long double

typedef pair<int, int> II;
typedef pair<int, II> III;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int POW(int a, int b){
    if(b == 0) return 1;
    if(b == 1) return a;
    int c = POW(a, b / 2);
    c = (c * c) % MOD;
    if(b % 2 == 1) c = (c * a) % MOD;
    return c;
}

void solve(){
    int k;
    cin >> k;
    cout << (POW(4, (1ll << k) - 2) * 6) % MOD << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
