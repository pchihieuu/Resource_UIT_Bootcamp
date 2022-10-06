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

int l, r;

int val(int n){
	int ans = 0;
	int p = 1;
	for(int i = 1; i <= 10; i++){
		p *= 10;
		int x = n;
		if(x < p) break;
		x -= x % p;
		x -= 1;
		x /= p;
		ans += x + 1;
	}
	return ans;
}

void solve(){
	cin >> l >> r;
	cout << r - l + val(r) - val(l) << '\n';
}


int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}