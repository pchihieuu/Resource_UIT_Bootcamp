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

int n;
II a[N];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a + 1, a + n + 1);
	int l = 0, c = 0;
	for(int i = 1; i <= n; i++){
		if(i == 1 || a[i].fi == a[1].fi){
			if(a[i].se % 2) l += 1;
			else c += 1;
		}
		else break;
	}
	if(abs(c - l) > 1){
		cout << "NO" << '\n';
		return;
	}


	int clock = c - l;
	a[n + 1].fi = 0;
	c = 0, l = 0;
	for(int i = 1; i <= n + 1; i++){
		if(i > 1 && a[i].fi != a[i - 1].fi){
			if(c - l != clock){
				cout << i << " " << c - l << endl;
				cout << "NO" << '\n';
				return;
			}
			c = 0, l = 0;
			if(a[i].se % 2) l += 1;
			else c += 1;
		}
		else{
			if(a[i].se % 2) l += 1;
			else c += 1;
		}
	}

	cout << "YES" << '\n';
}


int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}
}

