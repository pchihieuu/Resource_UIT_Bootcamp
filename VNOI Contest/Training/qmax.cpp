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
const int N = 5e4 + 5;

int n, m, p;
int a[N];
int it[4 * N], lazy[4 * N];

void build(int id, int l, int r){
	if(l == r){
		it[id] = a[l];
		lazy[id] = 0;
		return;
	}

	int m = (l + r) / 2;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	it[id] = max(it[id * 2], it[id * 2 + 1]);
}

void down(int id){
	lazy[id * 2] += lazy[id];
	lazy[id * 2 + 1] += lazy[id];

	it[id * 2] += lazy[id];
	it[id * 2 + 1] += lazy[id];

	lazy[id] = 0;
}


void update(int id, int l, int r, int u, int v, int k){
	if(l > v || r < u) return;
	if(u <= l && r <= v){
		it[id] += k;
		lazy[id] += k;
		return;
	}

	down(id);

	int m = (l + r) / 2;
	update(id * 2, l, m, u, v, k);
	update(id * 2 + 1, m + 1, r, u, v, k);
	it[id] = max(it[id * 2], it[id * 2 + 1]);
}

int query(int id, int l, int r, int u, int v){
	if(r < u || l > v) return -2147483647;
	if(u <= l && r <= v) return it[id];

	down(id);

	int m = (l + r) / 2;

	return max(query(id * 2, l, m, u, v), query(id * 2 + 1, m + 1, r, u, v));
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int T; cin >> T; while(T--){solve();} 
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		a[i] = 0;
	}

	for(int i = 1; i <= m; i++){
		int key, u, v, k;
		cin >> key;
		if(key == 0){
			cin >> u >> v >> k;
			update(1, 1, n, u, v, k);
		}
		else{
			cin >> u >> v;
			cout << query(1, 1, n, u, v) << '\n';
		}
		
	}

}