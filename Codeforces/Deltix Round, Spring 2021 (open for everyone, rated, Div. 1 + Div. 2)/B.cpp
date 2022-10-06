#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mp make_pair
#define pb push_back
typedef pair<int, int> II;
typedef pair<int, II> III;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 5, 0);
	vector<III> res;

	for(int i = 1; i <= n; i++){
		cin >> a[i];
		res.pb(mp(2, i, i + 1));
		res.pb(mp())
	}

	for(int i = 1; i <= n; i += 2){
		int u = i, v = i + 1;

	}

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	
}