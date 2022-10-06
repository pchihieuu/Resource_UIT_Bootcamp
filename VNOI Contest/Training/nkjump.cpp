#include<bits/stdc++.h>
using namespace std;

int n;
int a[1005];
map<int, vector<int> > e;
map<int, int> x, mark, f;

int dfs(int u){
	if(f.count(u)) return f[u];
	int val = 0;
	for(int v: e[u]){
		val = max(val, dfs(v));
	}
	return f[u] = val + 1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		x[a[i]] = 1;
	}

	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			int sum = a[i] + a[j];
			if(x.count(sum)){
				e[a[i]].push_back(sum);
				e[a[j]].push_back(sum);
			}
		}
	}

	int res = 0;
	for(int i = 1; i <= n; i++){
		res = max(res, dfs(a[i]));
	}

	cout << res << '\n'
}