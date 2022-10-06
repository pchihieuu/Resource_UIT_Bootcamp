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
	int x1, y1, x2, y2, fx, fy;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> fx >> fy;

	int val = abs(y2 - y1) + abs(x2 - x1);
	if(x1 == x2 && x1 == fx){
		if(min(y1, y2) <= fy && fy <= max(y1, y2)){
			cout << val + 2 << '\n';
		}
		else{
			cout << val << '\n';
		}
		return;
	}

	if(y1 == y2 && y1 == fy){
		if(min(x1, x2) <= fx && fx <= max(x1, x2)){
			cout << val + 2 << '\n';
		}
		else{
			cout << val << '\n';
		}
		return;
	}

	cout << val << '\n';
}


int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}