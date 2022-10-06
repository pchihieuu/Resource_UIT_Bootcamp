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
const int N = 5e5 + 5;

int n;
char a[N];
map<II, int> m;


void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	m.clear();

	int d = 0, k = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 'D') d += 1;
		else k += 1;
		int u = __gcd(d, k);
		int x = d / u, y = k / u;
		if(m.count(mp(x, y))){
			m[mp(x, y)] += 1;
			cout << m[mp(x, y)] << " ";
		}
		else{
			m[mp(x, y)] = 1;
			cout << m[mp(x, y)] << " ";
		}		
	}
	cout << '\n';
}


int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}