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
const int N = 2e5 + 5;

int n, l, r;
int a[N];

int trai(int x, int val){
	int l = 1, r = x;
	int ans = n + 1;
	while(l <= r){
		int m = (l + r) / 2;
		if(a[m] >= val){
			ans = min(ans, m);
			r = m - 1;
		}
		else l = m + 1;
	}
	return ans;
}

int phai(int x, int val){
	int l = 1, r = x;
	int ans = 0;
	while(l <= r){
		int m = (l + r) / 2;
		if(a[m] <= val){
			ans = max(ans, m);
			l = m + 1;
		}
		else r = m - 1;
	}
	return ans;
}
void solve(){
	cin >> n >> l >> r;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int res = 0;
	for(int i = 1; i <= n; i++){
		int L = trai(i - 1, l - a[i]);
		int R = phai(i - 1, r - a[i]);
		//cout << L << " " << R << endl;
		if(L <= R) res += R - L + 1;
	}
	cout << res << '\n';
}


int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}