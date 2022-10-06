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

int f[N][2];
int val[N];

void solve(){
	int n;
	string s;
	cin >> s;
	n = s.length();
	s = '@' + s;

	for(int i = 0; i <= n; i++){
		f[i][0] = 0;
		f[i][1] = 0;
	}

	int res = 0;

	if(s[1] == '?'){
		f[1][0] = 1;
		f[1][1] = 1;
	}
	else f[1][s[1] - '0'] = 1;
	res += max(f[1][0], f[1][1]);
	for(int i = 2; i <= n; i++){
		if(s[i] == '0'){
			f[i][0] = 1 + f[i - 1][1];
			f[i][1] = 0;
		}
		if(s[i] == '1'){
			f[i][1] = 1 + f[i - 1][0];
			f[i][0] = 0;
		}
		if(s[i] == '?'){
			f[i][0] = 1 + f[i - 1][1];
			f[i][1] = 1 + f[i - 1][0];
		}

		//cout << max(f[i][0], f[i][1]) << endl;
		res += max(f[i][0], f[i][1]);
	}
	cout << res << '\n';
}


int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}