#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;
const int N = 100000 + 5;

int n, m;
int a[N];
int f[N];

struct segment_tree{
	int n;
	vector<int> it;
	vector<int> a;

	void init(int n, int x[]){
		this-> n = n;
		a = vector<int> (n + 5, 0);
		it = vector<int> (4 * n + 5, 0);
		for(int i = 1; i <= n; i++){
			a[i] = x[i];
		}
	}

	void build(int id, int l, int r){
		if(l == r){
			it[id] = a[l];
			return;
		}
		int m = (l + r) / 2;
		build(id * 2, l, m);
		build(id * 2 + 1, m + 1, r);
		it[id] = max(it[id * 2], it[id * 2 + 1]);
	}

	int get(int id, int l, int r, int u, int v){
		if(l  > v || u > r) return 0;
		if(u <= l && r <= v){
			return it[id];
		}
		int m = (l + r) / 2;
		return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
	}
};

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	int mx = -INF;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}

	if(mx > m){
		cout << -1;
		return 0;
	}

	segment_tree it;
	it.init(n, a);
	it.build(1, 1, n);

	for(int i = 1; i <= n; i++){
		f[i] = INF;
	}

	int sum = 0, val = 0;
	int tail = 1;
	for(int i = 1; i <= n; i++){
		while(sum + a[i] > m){
			sum -= a[tail];
			tail += 1;
			val = it.get(1, 1, n, tail, i - 1);
			if(tail <= i - 1){
				f[i - 1] = min(f[i - 1], f[tail - 1] + val);
			}
		}
		
		sum += a[i];
		val = it.get(1, 1, n, tail, i);
		f[i] = min(f[i], f[tail - 1] + val);		
	}
	
	while(tail < n){
		sum -= a[tail];
		tail += 1;
		val = it.get(1, 1, n, tail, n);
		f[n] = min(f[n], f[tail - 1] + val);
	}
	cout << f[n];
}