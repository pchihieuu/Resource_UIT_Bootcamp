#include <bits/stdc++.h>
using namespace std;

#define int long long

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = (1ll << 30) - 1;
const long long oo = (1ll << 62) - 1;
const long double PI = 3.1415926535898;

const int N = 2e5 + 5;

int n, k, m;
vector<int> a[N];

int col[N], hight[N], pos[N], vt[N], head[N], bac[N], par[N], p[N];
int cnt = 0, Time = 0;
vector<int> mau[N];
int kq[N];
int mark[N];

void DFS(int u)
{
    mark[u] = 1;
    bac[u] = 1;
    for(int i = 0; i < a[u].size(); i++){
        int v = a[u][i];
        if(v == par[u]) continue;
        par[v] = u;
        DFS(v);
        bac[u] += bac[v];
    }
}

void HLD(int u)
{
    if(head[cnt] == 0) head[cnt] = u;
    col[u] = cnt;
    mau[cnt].pb(u);
    pos[u] = ++Time;
    vt[Time] = u;
    int hv = -1;
    for(int i = 0; i < a[u].size(); i++){
        int v = a[u][i];
        if(v == par[u]) continue;
        if(hv == -1 || bac[hv] < bac[v]) hv = v;
    }
    if(hv != -1) HLD(hv);
    for(int i = 0; i < a[u].size(); i++){
        int v = a[u][i];
        if(v == par[u] || v == hv) continue;
        cnt += 1;
        hight[cnt] = hight[col[u]] + 1;
        HLD(v);
    }
}

int LCA(int u, int v)
{
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

int LCA2(int u, int v){
    while(col[u] != col[v]){
        int val = par[head[col[v]]];
        if(val == u){
            return head[col[v]];
        }
        v = val;
    }

    return kq[u];
}

int finds(int u){
    return p[u] < 0 ? u : p[u] = finds(p[u]);
}

void join(int u, int v){
    u = finds(u);
    v = finds(v);
    if(u == v){
        return;
    }
    if(p[u] > p[v]) swap(u, v);
    p[u] += p[v];
    p[v] = u;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        p[i] = -1;
    }
    for(int i = 1; i <= k; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
        join(u, v);
    }
    for(int i = 1; i <= n; i++){
        if(mark[i]) continue;
        DFS(i);
        HLD(i);
    }

    for(int i = 0; i <= cnt; i++){
        if(mau[i].size() > 1){
            for(int j = 1; j < mau[i].size(); j++){
                kq[mau[i][j - 1]] = mau[i][j];
            }
        }
    }

    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v, p;
        cin >> u >> v;
        int U = finds(u);
        int V = finds(v);
        if(U != V){
            cout << -1 << '\n';
        }
        else{
            p = LCA(u, v);
            if(p != u){
                cout << par[u] << '\n';
            }
            else {
                cout << LCA2(u, v) << '\n';
            }
        }
    }
}
