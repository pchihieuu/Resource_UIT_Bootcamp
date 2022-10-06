#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
vector<int> a[N];
int d[N];

void dfs(int u){
    if(d[u]) return;
    d[u] = 1;
    for(int v: a[u]){
        dfs(v);
        d[u] = max(d[u], 1 + d[v]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
        if(d[i]) continue;
        dfs(i);
        res = max(res, d[i]);
    }

    cout << res - 1;

}
