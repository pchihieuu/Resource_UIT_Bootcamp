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

struct DinicFlow{
    struct Edge{
        int u, v, cap, flow;
        Edge(){}
        Edge(int u, int v, int cap, int flow): u(u), v(v), cap(cap), flow(flow){}
    };

    int n, s, t;
    vector<vector<int> > a;
    vector<int> d, cur;
    vector<Edge> e;

    DinicFlow() {};

    DinicFlow(int n, int s, int t): n(n), s(s), t(t), a(n + 5), d(n + 5, 0), cur(n + 5, 0){}

    void addEdge(int u, int v, int cap){
        a[u].push_back(e.size()); e.push_back(Edge(u, v, cap, 0));
        a[v].push_back(e.size()); e.push_back(Edge(v, u, 0, 0));
    }

    bool bfs(){
        for(int i = 1; i <= n; i++){
            d[i] = -1;
        }
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while(q.size()){
            int u = q.front();
            q.pop();
            for(int i = 0; i < a[u].size(); i++){
                int id = a[u][i];
                int v = e[id].v;
                if(e[id].cap > e[id].flow && d[v] < 0){
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return d[t] > 0;
    }

    int dfs(int u, int val){
        if(val == 0) return val;
        if(u == t) return val;
        for(; cur[u] < a[u].size(); cur[u]++){
            int id = a[u][cur[u]];
            int v = e[id].v;
            if(d[v] != d[u] + 1) continue;
            int ans = dfs(v, min(val, e[id].cap - e[id].flow));
            if(ans){
                e[id].flow += ans;
                e[id ^ 1].flow -= ans;
                return ans;
            }
        }
        return 0;
    }

    void Answer(){
        int maxFlow = 0;
        while(bfs()){
            for(int i = 1; i <= n; i++)
                cur[i] = 0;
            while(1){
                int ans = dfs(s, INF);
                if(!ans) break;
                maxFlow += ans;
            }
        }
        cout << maxFlow << '\n';
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, s, t, u, v, c;
    cin >> n >> m >> s >> t;
    DinicFlow g(n, s, t);
    for(int i = 1; i <= m; i++){
        cin >> u >> v >> c;
        g.addEdge(u, v, c);
    }
    g.Answer();
}
