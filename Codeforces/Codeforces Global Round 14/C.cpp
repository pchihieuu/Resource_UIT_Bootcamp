#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int N = 1e5 + 5;

int n, m, x;
II a[N];
int ans[N];
priority_queue<II, vector<II>, greater<II> > h;



void solve(){
	cin >> n >> m >> x;
	for(int i = 1; i <= n; i++){
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a + 1, a + n + 1, [](II a, II b){
		return a.fi > b.fi;
	});

	while(h.size()) h.pop();

	for(int i = 1; i <= m; i++){
		h.push(mp(0, i));
	}

	for(int i = 1; i <= n; i++){
		II val = h.top();
		h.pop();
		val.fi += a[i].fi;
		ans[a[i].se] = val.se;
		h.push(val);
	}

	int mi = 1e15, ma = 0;
	while(h.size()){
		if(h.top().fi == 0){
			cout << "NO" << '\n';
			return;
		}
		mi = min(mi, h.top().fi);
		ma = max(ma, h.top().fi);
		h.pop();
	}
	if(ma - mi > x){
		cout << "NO" << '\n';
		return;
	}

	cout << "YES" << '\n';
	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	cout << '\n';
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}

}
