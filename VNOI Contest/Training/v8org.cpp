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
const int N = 1e4 + 5;

int n, k;
vector<int> a[N];
int d[N];
int res = 0;

void dfs(int u, int p){
	for(int v: a[u]){
		if(v == p) continue;
		dfs(v, u);
		d[u] += d[v];
	}
	if(d[u] >= k){
		d[u] = 0;
		res += 1;
	}
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int T; cin >> T; while(T--){solve();}

	cin >> k;
	cin >> n;
	for(int i = 2; i <= n; i++){
		int x;
		cin >> x;
		a[x].pb(i);
		a[i].pb(x);
	}

	for(int i = 1; i <= n; i++){
		d[i] = 1;
	}
	dfs(1, 1);
	cout << res << endl;
}