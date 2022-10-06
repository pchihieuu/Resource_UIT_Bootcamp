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

int n, d, t;
III a[N];
int f[N][2];

void solve(){
    cin >> n >> d >> t;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se.fi >> a[i].se.se;
    }
    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n; i++){
        f[i][0] = -1;
        f[i][1] = -1;
    }

    f[1][0] = a[1].fi - t;
    if(a[1].se.se == 1){
        f[1][1] = a[1].se.fi;
    }

    for(int i = 2; i <= n; i++){
        if(f[i - 1][0] != -1){
            f[i][0] = f[i - 1][0];
            if(a[i].fi - a[i - 1].se.fi >= 2 * t){
                f[i][0] += a[i].fi - a[i - 1].se.fi - 2 * t;
            }
        }
        if(f[i - 1][1] != -1 && a[i].fi - a[i - 1].se.fi >= t){
            f[i][0] = max(f[i][0], f[i - 1][1] + a[i].fi - a[i - 1].se.fi - t);
        }

        if(a[i].se.se == 1){
            if(f[i - 1][1] != -1){
                f[i][1] = f[i - 1][1] + a[i].se.fi - a[i - 1].se.fi;
            }
            if(f[i - 1][0] != -1 && a[i].fi - a[i - 1].se.fi >= t){
                f[i][1] = max(f[i][1], f[i - 1][0] + a[i].se.fi - a[i].fi + a[i].fi - a[i - 1].se.fi - t);
            }

        }
    }
    int res = 0;
    if(f[n][1] != -1) res += f[n][1] + d - a[n].se.fi;
    if(f[n][0] != -1){
        res = max(res, f[n][0] + d - a[n].se.fi - t);
    }
    cout << res;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
