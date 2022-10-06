#include<bits/stdc++.h>
using namespace std;

//#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 5e4 + 5;

int n, m, k;
int a[N], b[N];


int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int T; cin >> T; while(T--){solve();}

	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> b[i];
	}

	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);

	priority_queue<III, vector<III>, greater<III> > heap;

	for(int i = 1; i <= m; i++){
		heap.push(mp(a[1] + b[i], mp(1, i)));
	}	

	vector<int> res;

	while((int)res.size() < k){
		III val = heap.top();
		heap.pop();
		res.pb(val.fi);
		if(val.se.fi < n)
			heap.push(mp(a[val.se.fi + 1] + b[val.se.se], mp(val.se.fi + 1, val.se.se)));
		
	}
	for(int i: res) cout << i << '\n';
}