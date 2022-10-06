#include<bits/stdc++.h>
using namespace std;

#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;


int n;
int p[N], q[N], s[N];
int Test = 0;

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> p[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> q[i];
	}
	int sum = 0;
	for (int i = 1; i <= n; i++){
		s[i] = p[i] - q[i];
		sum += s[i];
	}
	for(int i = n + 1; i <= 2 * n; i++){
		s[i] = s[i - n];
	}

	int pos = 1, val = 0;
	for(int i = 1; i <= 2 * n; i++){
		val += s[i];
		if(val < 0){
			val = 0;
			pos = i + 1;
		}
	}
	cout << "Case " << ++Test << ": ";
	if (pos > n || sum < 0)
		cout << "Not possible" << '\n';
	else
		cout << "Possible from station " << pos << '\n';
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}