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

int n, m;
int a[N];

struct node{
	int f, l, r, val;
	
	node(){}
	node(int f, int l, int r, int val){
		this->f = f; this->l = l; this->r = r; this->val = val;
	}
};

node st[4 * N];

node merge(node L, node R){
	node x;
	x.f = L.f + R.f;
	x.l = max(L.l, L.f + R.l);
	x.r = max(R.r, R.f + L.r);
	x.val = max(L.val, max(R.val, L.r + R.l));
	return x;
}

void build(int id, int l, int r){
	if(l == r){
		st[id] = node(a[l], a[l], a[l], a[l]);
		return;
	}
	int m = (l + r) / 2;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

node query(int id, int l, int r, int u, int v){
	if(r < u || v < l) return node(0ll, -1e9, -1e9, -1e9);
	if(u <= l && r <= v) return st[id];
	int m = (l + r) / 2;
	node T = query(id * 2, l, m, u, v);
	node P = query(id * 2 + 1, m + 1, r, u, v);
	return merge(T, P);
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int T; cin >> T; while(T--){solve();}

	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	build(1, 1, n);

	cin >> m;
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		int val = query(1, 1, n, u, v).val;
		cout << val << '\n';
	}
	int x = 2;
	cout << st[x].f << " " << st[x].l << " " << st[x].r << " " << st[x].val << '\n';
	
}
/*
8
-1 -1 -1 5 10 10 -1 -1
1
1 8

6
10 9 -2 -2 9 10
3
4 6
3 6
2 6
*/