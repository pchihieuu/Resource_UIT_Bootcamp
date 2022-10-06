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

void solve(){
	int n;
	cin >> n;
	int val = 0;
	for(int i = 1; i <= 2 * n; i++){
		int x;
		cin >> x;
		if(x & 1) val += 1;
		else val -= 1;
	}

	if(val == 0) cout << "Yes";
	else cout << "No";
	cout << '\n';
}


int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}