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

struct MincostFlow{
    struct Edge{
        int u, v, cost, cap, flow;
        Edge() {}
        Edge(int u, int v, int cost, int cap, int flow): u(u), v(v), cost(cost), cap(cap), flow(flow){}
    };

    int n, k;
    vector<int> mark, trace, d, cnt;
    vector<vector<int> > a;
    vector<Edge> e;

    MincostFlow() {}

    MincostFlow(int n, int k): n(n), k(k), d(n + 5), trace(n + 5), mark(n + 5), a(n + 5), cnt(n + 5){}

    void addEdge(int u, int v, int cost, int cap){
        a[u].pb(e.size()); e.pb(Edge(u, v, cost, cap, 0));
        a[v].pb(e.size()); e.pb(Edge(v, u, -cost, 0, 0));
    }

    bool bellmanFord(int s, int t){
        for(int i = 1; i <= n; i++){
            trace[i] = -1;
            d[i] =  INF;
            mark[i] =  false;
            cnt[i] = 0;
        }
        queue<int> q;
        q.push(s);
        d[s] = 0;
        mark[s] = true;

        while(q.size()){
            int u = q.front();
            q.pop();
            mark[u] = false;
            for(auto i: a[u]){
                if(e[i].cap - e[i].flow <= 0) continue;
                int v = e[i].v;
                if(d[v] > d[u] + e[i].cost){
                    d[v] = d[u] + e[i].cost;
                    trace[v] = i;
                    if(!mark[v]){
                        q.push(v);
                        mark[v] = true;

                        cnt[v] += 1;
                        if(cnt[v] > n){
                            return false;  /// Negative cycle
                        }
                    }
                }
            }
        }
        return d[t] < INF;
    }

    II edmondsKarp(int s, int t)
    {
        int resFlow = 0, resCost = 0;
        while(bellmanFord(s, t)){
            int ans = INF;
            for(int v = t; v != s; v = e[trace[v]].u){
                ans = min(ans, e[trace[v]].cap - e[trace[v]].flow);
            }
            for(int v = t; v != s; v = e[trace[v]].u){
                e[trace[v]].flow += ans;
                e[trace[v] ^ 1].flow -= ans;
            }
            resFlow += ans;
            resCost += d[t];
        }
        ///{maxFlow, minCost}
        return {resFlow, resCost};
    }

    void minCost(int s, int t){
        II res = edmondsKarp(s, t);

        if(res.first < k){
            cout << -1;
            return;
        }

        cout << res.second << '\n';

        queue<int> q[n + 5];
        vector<int> ans;
        for(int i = 0; i < e.size(); i++){
            if(i % 2 == 0 && e[i].flow > 0 && e[i].u < n){
                q[e[i].u].push(e[i].v);
            }
        }
        for(int i = 1; i <= k; i++){
            ans.clear();
            int v = s;
            while(v != t){
                ans.pb(v);
                int u = q[v].front();
                q[v].pop();
                v = u;
            }
            ans.push_back(t);

            cout << ans.size();
            for(auto i: ans) cout << " " << i;
            cout << '\n';
        }
    }
};


int n, m, k, s, t, u, v, c;
MincostFlow g;

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s >> t;
    /// HIWAY: Find 2 shortest independent paths from S to T
    k = 2;
    g = MincostFlow(n + 1, k);
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> c;
        g.addEdge(u, v, c, 1);
        g.addEdge(v, u, c, 1);
    }
    g.addEdge(n + 1, s, 0, k);
    g.minCost(s, t);
}
