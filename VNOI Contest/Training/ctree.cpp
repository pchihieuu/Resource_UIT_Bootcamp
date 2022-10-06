#include<bits/stdc++.h>
using namespace std;

//#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n;
vector<int> a[N];
int f[N][10];
int c[N];

int X = 10;

void dfs(int u, int p){
	for(int i = 1; i <= X; i++){
		f[u][i] = i;
	}
	for(int v: a[u]){
		if(v == p) continue;
		dfs(v, u);
		for(int i = 1; i <= X; i++){
			int val = INF;
			for(int j = 1; j <= X; j++){
				if(j == i) continue;
				val = min(f[v][j], val);
			}
			f[u][i] += val;
		}
	}
}

void dfs2(int u, int p, int col){
	c[u] = col;
	for(int v: a[u]){
		if(v == p) continue;

		int pos = 0, val = INF;
		for(int i = 1; i <= X; i++){
			if(i == col) continue;
			if(f[v][i] < val){
				val = f[v][i];
				pos = i;
			}
		}
		dfs2(v, u, pos);
	}
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int T; cin >> T; while(T--){solve();}

	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}

	dfs(1, 1); // Caculate

	int col = 0, val = INF;
	for(int i = 1; i <= X; i++){
		if(f[1][i] < val){
			val = f[1][i];
			col = i;
		}
	}
	dfs2(1, 1, col);
	cout << f[1][col] << '\n';
	for(int i = 1; i <= n; i++){
		cout << c[i] << '\n';
	}

}