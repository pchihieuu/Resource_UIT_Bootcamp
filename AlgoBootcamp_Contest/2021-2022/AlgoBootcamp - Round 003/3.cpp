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

int n;
int pos[N];

void solve(){
	for(int i = 1; i <= n; i++){
		pos[i] = 0;
	}

	int check = 0;
	for(int i = 1; i <= n; i++){
		int c, p;
		cin >> c >> p;
		if((i + p < 1) || (i + p > n) || (pos[i + p] != 0)) check = 1;
		if(check) continue;
		pos[i + p] = c;
	}

	if(check){
		cout << -1 << '\n';
	}
	else{
		for(int i = 1; i <= n; i++){
			cout << pos[i] << " ";
		}
		cout << '\n';
	}
	
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n){
		if(n == 0) return 0;
		solve();
	}
}
