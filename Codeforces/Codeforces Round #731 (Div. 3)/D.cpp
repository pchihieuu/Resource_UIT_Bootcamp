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
const int N = 1e5 + 5;


void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 5, 0), b(n + 5, 0), res;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	res.push_back(0);
	for(int i = 2; i <= n; i++){
		int x = a[i - 1];
		int val = 0;
		for(int t = 0; t <= 30; t++){
			if((x >> t & 1) && (a[i] >> t & 1) == 0){
				val = val | (1 << t);
				a[i] = a[i] | (1 << t);
			}
		}
		res.push_back(val);
	}
	for(int i: res) cout << i << " ";
	cout << '\n';
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}