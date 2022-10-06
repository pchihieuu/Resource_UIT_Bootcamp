#include<bits/stdc++.h>
using namespace std;

#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 5e5 + 5;

int s, b;

II a[N];

void solve(){
	for(int i = 1; i <= s; i++){
		a[i].fi = i - 1;
		a[i].se = i + 1;
	}
	for(int i = 1; i <= b; i++){
		int l, r;
		cin >> l >> r;
		a[a[l].fi].se = a[r].se;
		a[a[r].se].fi = a[l].fi;

		if(a[l].fi == 0) cout << "*" << " ";
		else cout << a[l].fi << " ";
		if(a[r].se > s) cout << "*" << " ";
		else cout << a[r].se << " ";
		cout << '\n';
	}
	cout << "-" << '\n';
	
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	while(cin >> s >> b){
		if(s == 0 && b == 0){
			return 0;
		}
		solve();
	}
	
}