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
const int N = 1e3 + 5;

int n;
III a[N];
int dp[20004];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se.fi >> a[i].se.se;
    }

    sort(a + 1, a + n + 1, [](const III &a, const III &b){
         return a.fi + a.se.fi < b.fi + b.se.fi;
         });

    for(int i = 1; i <= n; i++){
        for(int j = a[i].se.fi ; j >= 0; j--){
            dp[j + a[i].fi] = max(dp[j + a[i].fi], dp[j] + a[i].se.se);
        }
    }

    cout << *max_element(dp  + 1, dp + 20000 + 1);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
