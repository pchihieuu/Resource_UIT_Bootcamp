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
int a[N];
priority_queue<II> h;

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	a[0] = 0, a[n + 1] = 0;

	for(int i = 1; i <= n; i++){
		h.push(mp(a[i], i));
	}

	int res = 0;

	while(h.size()){
		int i = h.top().se;
		h.pop();

		int val = max(a[i - 1], a[i + 1]);
		if(a[i] > val){
			res += a[i] - val;
			a[i] = val;
			h.push(mp(a[i], i));
		}
	}

	for(int i = 1; i <= n + 1; i++){
		res += abs(a[i] - a[i - 1]);
	}

	cout << res << '\n';
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}