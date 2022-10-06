#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mp make_pair

const int N = 5e4 + 5;

typedef pair<int, int> II;
vector<II> it[4 * N];
int lazy[4 * N];

int n, q;

void merge(int id){
	vector<II> x;
	for(int i = 0; i < (int)it[id * 2].size(); i++)
		x.push_back(it[id * 2][i]);
	for(int i = 0; i < (int)it[id * 2 + 1].size(); i++)
		x.push_back(it[id * 2 + 1][i]);

	sort(x.begin(), x.end(), [](II a, II b){
		if(a.first == b.first) return a.second > b.second;
		return a.first > b.first;
	});
	while((int)x.size() > 5) x.pop_back();
	it[id] = x;
}

void build(int id, int l, int r){
	if(l == r){
		it[id].clear();
		it[id].push_back(mp(0, l));
		for(int i = 1; i <= 4; i++){
			it[id].push_back(mp(-1e18, 0));
		}
		return;
	}
	int m = (l + r) / 2;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	merge(id);
}

void down(int id){
	int x = lazy[id];
	lazy[id * 2] += x;
	lazy[id * 2 + 1] += x;
	for(int i = 0; i < 5; i++){
		it[id * 2][i].first += x;
	}

	for(int i = 0; i < 5; i++){
		it[id * 2 + 1][i].first += x;
	}
	lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val){
	if(u > r || v < l) return;
	if(u <= l && r <= v){
		for(int i = 0; i < 5; i++){
			it[id][i].first += val;
		}
		lazy[id] += val;
		sort(it[id].begin(), it[id].end(), [](II a, II b){
			if(a.first == b.first) return a.second > b.second;
			return a.first > b.first;
		});
		return;	
	}

	down(id);
	int m = (l + r) / 2;
	update(id * 2, l, m, u, v, val);
	update(id * 2 + 1, m + 1, r, u, v, val);
	merge(id);
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;

	for(int i = 0; i < 4 * N; i++){
		for(int j = 0; j < 5; j++){
			it[i].push_back(mp(-1e18, 0));
		}
	}
	build(1, 1, n);

	for(int i = 1; i <= q; i++){
		int key, l, r, v, k;
		cin >> key;
		if(key == 1){
			cin >> l >> r >> v;
			update(1, 1, n, l, r, v);
		}
		else{
			cin >> k;
			for(int i = 0; i < k; i++){
				if(i > (int)it[1].size()) break;
				if(it[1][i].second <= 0) break;
				cout << it[1][i].second << " ";
			}
			cout << '\n';
		}
	}

	

}
/*
7 4

2 3

1 1 5 5

1 2 6 -7

2 8
*/