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
const int N = 1e5 + 5;

int a[1005], b[1005];

void solve(){
	int k, n, m;
	cin >> k >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	vector<int> res;

	int i = 1, j = 1;
	while(i <= n || j <= m){
		if(i > n){
			if(b[j] > k){
				cout << -1 << '\n';
				return;
			}
			if(b[j] == 0) k += 1;
			res.push_back(b[j]);
			j += 1;
			continue;
		}
		if(j > m){
			if(a[i] > k){
				cout << -1 << '\n';
				return;
			}
			if(a[i] == 0) k += 1;
			res.push_back(a[i]);
			i += 1;
			continue;
		}

		if(a[i] == 0){
			k += 1;
			res.push_back(a[i]);
			i += 1;
			continue;
		}

		if(b[j] == 0){
			k += 1;
			res.push_back(b[j]);
			j += 1;
			continue;
		}

		if(a[i] <= b[j]){
			if(a[i] > k){
				cout << -1 << '\n';
				return;
			}
			else{
				res.push_back(a[i]);
				i += 1;
			}
		}
		else{
			if(b[j] > k){
				cout << -1 << '\n';
				return;
			}
			else{
				res.push_back(b[j]);
				j += 1;
			}
		}
	}

	for(int i: res) cout << i << " ";
	cout << '\n';


}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}