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

struct HeavyLightDecomposition{
    int n;
    vector<vector<pair<int, int> > > a;
    vector<int> col, hight, pos, vt, head, bac, par;
    vector<int> d;
    int cnt = 0, Time = 0;

    HeavyLightDecomposition(){}

    HeavyLightDecomposition(int n): n(n), a(n + 5), col(n + 5, 0), hight(n + 5, 0),
        pos(n + 5, 0), vt(n + 5, 0), head(n + 5, 0), bac(n + 5, 0), par(n + 5, 0), d(n + 5, 0){
        cnt = 0;
        Time = 0;
    }

    void addEdge(int u, int v, int w){
        a[u].push_back(make_pair(w, v));
        a[v].push_back(make_pair(w, u));
    }

    void DFS(int u, int val){
        d[u] = val;
        bac[u] = 1;
        for(int i = 0; i < a[u].size(); i++){
            int v = a[u][i].se;
            int w = a[u][i].fi;
            if(v == par[u]) continue;
            par[v] = u;
            DFS(v, val + w);
            bac[u] += bac[v];
        }
    }

    void HLD(int u){
        if(head[cnt] == 0) head[cnt] = u;
        col[u] = cnt;
        pos[u] = ++Time;
        vt[Time] = u;
        int hv = -1;
        for(int i = 0; i < a[u].size(); i++){
            int v = a[u][i].se;
            if(v == par[u]) continue;
            if(hv == -1 || bac[hv] < bac[v]) hv = v;
        }
        if(hv != -1) HLD(hv);
        for(int i = 0; i < a[u].size(); i++){
            int v = a[u][i].se;
            if(v == par[u] || v == hv) continue;
            cnt += 1;
            hight[cnt] = hight[col[u]] + 1;
            HLD(v);
        }
    }

    int LCA(int u, int v){
        while(col[u] != col[v]){
            if(hight[col[u]] > hight[col[v]]){
                u = par[head[col[u]]];
            }
            else{
                v = par[head[col[v]]];
            }
        }

        if(pos[u] > pos[v]) swap(u, v);
        return u;
    }

    int query(int u, int v){
        int p = LCA(u, v);
        return (d[u] + d[v] - d[p] * 2);
    }
};

int n, m;

int main()
{
    /// pwalk: Find the length of the path from u to v
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    HeavyLightDecomposition g(n);
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    g.DFS(1, 0);
    g.HLD(1);

    for(int i = 1; i <= m; i++)
    {
        int u, v, p;
        cin >> u >> v;
        cout << g.query(u, v) << '\n';
    }
}

/**
TEST:


*/
