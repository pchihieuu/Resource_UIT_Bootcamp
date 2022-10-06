#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

const int N = 1e5 + 5;

int n;
vector<int> a[N];
int f[N][2];

int dfs(int u, int p, int col){
    if(f[u][col] != -1) return f[u][col];
    int val = 1;
    for(int v: a[u]){
        if(v == p) continue;
        if(col == 0){
            val *= dfs(v, u, col) + dfs(v, u, col ^ 1);
            val %= MOD;
        }
        else{
            val *= dfs(v, u, col ^ 1);
            val %= MOD;
        }
    }
    return f[u][col] = val;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        f[i][0] = -1;
        f[i][1] = -1;
    }

    dfs(1, 1, 0);
    dfs(1, 1, 1);
    cout << (f[1][0] + f[1][1]) % MOD;
}
