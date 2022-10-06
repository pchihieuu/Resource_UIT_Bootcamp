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
const int N = 4e5 + 5;

int n;
int a[N], b[N];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);

	for(int i = 1; i <= n; i++) a[i] += a[i - 1], b[i] += b[i - 1];

	int l = 0, r = 2e5;
	int res = 1e9;
	
	while(l <= r){
		int m = (l + r) / 2;
		int d = (m + n) / 4;
		if(d > n) d = n;
		int val1 = a[n] + m * 100 - a[d];
		int val2 = b[n] - b[max(0ll, d - m)];
		if(val1 >= val2){
			res = m;
			r = m - 1;
		}
		else l = m + 1;
	}

	cout << res << '\n';
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}