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

int np(int x, int y){
	int res = 1;
	int l = 1, r = 2e5;
	while(l <= r){
		int m = (l + r) / 2;
		if(x * m >= y){
			res = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	return res;
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 5, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int res = 0;
	for(int i = 1; i <= n; i++){
		int val = np(a[i], i);
		while(a[i] * val <= (i - 1) + i){
			if(a[i] * val - i < i){
				if(a[a[i] * val - i] == val){
					res += 1;
				}
			}
			else break;
			val += 1;
		}
	}
	cout << res << '\n';
}


int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}