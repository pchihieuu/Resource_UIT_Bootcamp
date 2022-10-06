#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> II;

const int N = 1e5 + 5;

int n;
vector<int> a[N];
II f[N], s[N];

II dp(int u, int p){
	II res = make_pair(0, 0);
	for(int v: a[u]){
		if(v == p) continue;
		II val = dp(v, u);
		res.first += max(abs(s[u].first - s[v].first) + val.first, 
			abs(s[u].first - s[v].second) + val.second);
		res.second += max(abs(s[u].second - s[v].first) + val.first,
			abs(s[u].second - s[v].second) + val.second);
	}
	return res;
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		f[i] = make_pair(0, 0);
		a[i].clear();
	}

	for(int i = 1; i <= n; i++){
		cin >> s[i].first >> s[i].second;
	}

	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	II res = dp(1, 1);
	cout << max(res.first, res.second) << '\n';
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}