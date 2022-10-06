#include<bits/stdc++.h>
using namespace std;

//#define int long long

int n;
map<int, vector<int>> e;
map<int, int> x, mark, res;
int a[1005];

int dfs(int u){
	if(res.count(u)) return res[u];
	int val = 0;
	for(int v: e[u]){
		if(mark.count(v)) continue;
		mark[v] = 1;
		val = max(val, dfs(v));
	}
	return res[u] = val + 1;
}

int32_t main(){
	
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		x[a[i]] = 1;
	}

	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(x.count(a[i] + a[j])){
				e[a[i]].push_back(a[i] + a[j]);
				e[a[j]].push_back(a[i] + a[j]);
			}
		}
	}

	
	for(int i = 1; i <= n; i++){
		mark[a[i]] = 1;
		dfs(a[i]);
	}

	int ans = 0;
	for(auto it: res){
		ans = max(ans, it.second);
	}

	cout << ans;
}