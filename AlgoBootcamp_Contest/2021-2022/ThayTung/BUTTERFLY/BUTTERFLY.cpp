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
const int N = 2e5 + 5;

int n;
vector<int> a[N];
int dp[N];
int h[N];

void dfs(int u, int p, int deep){
    int cnt = 0;
    h[u] = INF;
    for(int v: a[u]){
        if(v == p) continue;
        dfs(v, u, deep + 1);
        h[u] = min(h[u], h[v] + 1);
        cnt += 1;
        dp[u] += dp[v];
    }
    if(cnt == 0) h[u] = 0;
    if(h[u] <= deep) dp[u] = 1;
}

void solve(){
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    dfs(1, 1, 0);
    cout << dp[1];
}

void sol_ThayTung(){
    int n;
    cin >> n;
    vector<vector<int> > graph(n);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> dp(n);
    vector<int> nearest(n);
    function<void(int, int, int)> dfs = [&](int v, int p, int d){
        nearest[v] = INF;
        int cnt = 0;
        for(int to: graph[v]){
            if(to != p){
                ++cnt;
                dfs(to, v, d + 1);
                nearest[v] = min(nearest[v], nearest[to] + 1);
                dp[v] += dp[to];
            }
        }
        if(!cnt) nearest[v] = 0;
        if(nearest[v] <= d) dp[v] = 1;
    };
    dfs(0, 0, 0);
    cout << dp[0];
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
    //sol_ThayTung();

}
/**
10
10 6
6 5
1 3
6 1
7 10
2 8
9 7
3 4
4 8
*/
