#include<bits/stdc++.h>
using namespace std;

const int N = 3e4 + 5;

int n;
int a[N];
int f[N];
int it[4 * N];

void build(int id, int l, int r){
	if(l == r){
		it[id] = 0;
		return;
	}
	int m = (l + r) / 2;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	it[id] = max(it[id * 2], it[id * 2 + 1]);
}

void update(int id, int l, int r, int x, int val){
	if(x < l || x > r) return;
	if(l == r){
		it[id] = max(it[id], val);
		return;
	}

	int m = (l + r) / 2;
	update(id * 2, l, m, x, val);
	update(id * 2 + 1, m + 1, r, x, val);
	it[id] = max(it[id * 2], it[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v){
	if(l > v || r < u) return 0;
	if(u <= l && r <= v){
		return it[id];
	}

	int m = (l + r) / 2;
	return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	vector<pair<int, int> > b;
	for(int i = 1; i <= n; i++){
		b.push_back(make_pair(a[i], i));
	}
	sort(b.begin(), b.end());
	int X = 0;
	for(int i = 0; i < (int)b.size(); i++){
		if(X == 0 || b[i].first > b[i - 1].first) X += 1;
		a[b[i].second] = X;
	}

	build(1, 1, 3e4);

	for(int i = 1; i <= n; i++){
		int val = get(1, 1, 3e4, 1, a[i] - 1);
		f[i] = max(f[i], val + 1);
		update(1, 1, 3e4, a[i], f[i]);
	}

	cout << get(1, 1, 3e4, 1, 3e4);


	
}