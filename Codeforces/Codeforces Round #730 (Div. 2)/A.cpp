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
	int a, b;
	cin >> a >> b;
	if(a < b) swap(a, b);
	if(a - b <= 1){
		cout << a - b << " " << 0 << '\n';
		return;
	}
	int val = a - b;
	cout << val << " ";
	cout << min(val - a % val, a % val) << '\n';
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}	
}