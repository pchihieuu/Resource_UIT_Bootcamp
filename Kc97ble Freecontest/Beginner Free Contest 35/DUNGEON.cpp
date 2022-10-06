#include<bits/stdc++.h>
using namespace std;

#define int long long

const int oo = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n;
vector<int> a[N], topo;
int pos[N], mark[N];
int d[N];

///Topo in DAG
void dfs(int u){
    mark[u] = 1;
    for(int v: a[u]){
        if(mark[v]) continue;
        dfs(v);
    }
    topo.push_back(u);
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        for(int j = 1; j <= x; j++){
            int v; cin >> v;
            a[i].push_back(v);
        }
    }

    for(int i = 1; i <= n; i++){
        if(mark[i]) continue;
        dfs(i);
    }

    for(int i = 0; i < topo.size(); i++){
        pos[topo[i]] = i;
    }

    int res = 1;
    for(int u: topo){
        d[u] = 1;
        for(int v: a[u]){
            if(pos[v] > pos[u]){
                cout << -1 << '\n';
                return 0; ///cycle
            }
            d[u] = max(d[u], d[v] + (v > u));
        }
        res = max(res, d[u]);
    }

    cout << res << '\n';
}
