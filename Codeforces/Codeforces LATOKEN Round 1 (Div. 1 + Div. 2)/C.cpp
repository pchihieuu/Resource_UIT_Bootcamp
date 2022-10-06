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
const int N = 8e5 + 5;

vector<int> e[N];
int d[N], a[N], b[N];;

int n;

void dfs(int u){
	d[u] = 1;
	for(int v: e[u]){
		if(d[v]) continue;
		dfs(v);
	}
}

int p(int a, int b){
	if(b == 0) return 1;
	if(b == 1) return a;
	int c = p(a, b / 2);
	c = (c * c) % MOD;
	if(b % 2 == 1) c = (c * a) % MOD;
	return c;
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}

	for(int i = 1; i <= n; i++){
		e[i].clear();
		d[i] = 0;
	}

	for(int i = 1; i <= n; i++){
		e[a[i]].pb(b[i]);
		e[b[i]].pb(a[i]);
	}
	int res = 0;
	for(int i = 1; i <= n; i++){
		if(d[i] == 0){
			res += 1;
			dfs(i);
		}
	}

	cout << p(2, res) << '\n';

}


int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}