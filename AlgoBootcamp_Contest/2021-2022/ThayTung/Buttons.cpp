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
const int N = 2e6 + 5;

int n, m;
int p[N];

int col[N];
int mark[N];
vector<II> e;
vector<int> a[N];
map<II, int> Map;

int finds(int u){
    return p[u] < 0 ? u : p[u] = finds(p[u]);
}

int join(int u, int v){
    u = finds(u);
    v = finds(v);
    if(u == v) return 0;
    if(p[u] > p[v]) swap(u, v);
    p[u] += p[v];
    p[v] = u;
    return 1;
}

int cnt;
vector<II> edge;

void dfs(int u){
    for(int v: a[u]){
        if(Map.find(mp(u, v)) != Map.end()) continue;
        Map[mp(u, v)] = 1;
        Map[mp(v, u)] = 1;
        int val = join(u, v);
        if(val == 1){
            col[v] = v;
            edge.pb(mp(u, v));
            dfs(v);
        }
        else{
            cnt += 1;
            col[cnt] = v;
            edge.pb(mp(u, cnt));
        }
    }
}


void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    for(int i = 1; i <= n; i++){
        p[i] = -1;
    }

    cnt = n;
    col[1] = 1;
    dfs(1);

    cout << cnt << '\n';
    for(int i = 1; i <= cnt; i++){
        cout << col[i] << " ";
    }
    cout << '\n';
    for(auto [u, v]: edge){
        cout << u << " " << v << '\n';
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
