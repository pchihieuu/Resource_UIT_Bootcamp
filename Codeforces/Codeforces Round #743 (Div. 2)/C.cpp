#include<bits/stdc++.h>
using namespace std;

#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int oo = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n;
vector<int> a[N], topo;
int pos[N], mark[N];
int d[N];

///Topo in DAG
void dfs(int u){
    if(mark[u]) return;
    mark[u] = 1;
    for(int v: a[u]){
        dfs(v);
    }
    topo.push_back(u);
}

///Find longest path in DAG
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        a[i].clear();
        mark[i] = 0;
    }
    topo.clear();

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        for(int j = 1; j <= x; j++){
            int v; cin >> v;
            a[i].push_back(v);
        }
    }

    for(int i = 1; i <= n; i++){
        dfs(i);
    }
    for(int i = 0; i < topo.size(); i++){
        int u = topo[i];
        pos[u] = i;
    }

    int res = 0;
    for(int u: topo){
        d[u] = 1;
        for(int v: a[u]){
            if(pos[v] > pos[u]){
                cout << -1 << '\n';
                return; //cycle
            }
            d[u] = max(d[u], d[v] + (u < v));
        }
        res = max(res, d[u]);
    }
    cout << res << '\n';

}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}
}
