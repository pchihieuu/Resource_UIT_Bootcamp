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
const int N = 1e6 + 5;

int n, m;
vector<int> a[N];
int col[N];
int cnt[2];
int X;

void check(int c, int u){
    if(X) return;
    col[u] = c;
    if(u <= n) cnt[c] += 1;

    for(int v: a[u]){
        if(col[v] != -1){
            if(col[v] == col[u]){
                X = 1;
            }
        }
        else{
            check(c ^ 1, v);
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n + m; i++){
        a[i].clear();
        col[i] = -1;
    }

    int fake = n + 1;
    for(int i = 1; i <= m; i++){
        int u, v;
        string c;
        cin >> u >> v >> c;
        if(c.back() == 'r'){
            a[u].pb(v);
            a[v].pb(u);
        }
        else{
            a[u].pb(fake);
            a[fake].pb(u);
            a[v].pb(fake);
            a[fake].pb(v);
            fake += 1;
        }
    }

    int res = 0;
    X = 0;
    for(int i = 1; i <= n; i++){
        cnt[0] = 0;
        cnt[1] = 0;
        if(col[i] == -1){
            check(0, i);
            res += max(cnt[0], cnt[1]);
        }
    }

    if(X){
        cout << -1 << '\n';
        return;
    }

    cout << res << '\n';

}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; while(T--)
    solve();
}
