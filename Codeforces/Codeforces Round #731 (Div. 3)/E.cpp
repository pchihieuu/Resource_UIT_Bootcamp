#include<bits/stdc++.h>
using namespace std;

#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 2e9;
const int MOD = 1e9 + 7;
const int N = 3e5 + 5;

int n, k;
int l[N], r[N], a[N], t[N], x[N];

void solve(){
	cin >> n >> k;
	for(int i = 0; i <= n + 1; i++)
		x[i] = INF;
	for(int i = 1; i <= k; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= k; i++){
		cin >> t[i];
	}

	for(int i = 1; i <= k; i++){
		x[a[i]] = t[i];
	}
	l[0] = INF;
	for(int i = 1; i <= n; i++){
		l[i] = min(x[i], l[i - 1] + 1);
	}
	r[n + 1] = INF;
	for(int i = n; i >= 1; i--){
		r[i] = min(x[i], r[i + 1] + 1);
	}

	for(int i = 1; i <= n; i++){
		cout << min(l[i], r[i]) << " ";
	}
	cout << '\n';
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}