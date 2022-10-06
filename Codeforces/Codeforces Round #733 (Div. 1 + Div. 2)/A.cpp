#include<bits/stdc++.h>
using namespace std;

#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e3 + 5;

int n, m;
vector<int> a[N], b[N];

int mark[N];

void dfs1(int u){
    for(int v: a[u]){
        if(mark[v]) continue;
        mark[v] = 1;
        dfs1(v);
    }
}

void dfs2(int u){
    for(int v: b[u]){
        if(mark[v]) continue;
        mark[v] = 1;
        dfs2(v);
    }
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        b[v].pb(u);
    }

    int U = 0, V = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            mark[j] = 0;
        }
        mark[i] = 1;
        dfs1(i);
        int check = 1;
        for(int j = 1; j <= n; j++){
            if(mark[j] == 0) check = 0;
        }
        if(check) U = i;

        for(int j = 1; j <= n; j++){
            mark[j] = 0;
        }
        mark[i] = 1;
        dfs2(i);
        check = 1;
        for(int j = 1; j <= n; j++){
            if(mark[j] == 0) check = 0;
        }
        if(check) V = i;
    }

    if(U != 0 && V != 0){
        cout << "YES" << '\n';
        cout << V << " " << U;
    }
    else cout << "NO";
}