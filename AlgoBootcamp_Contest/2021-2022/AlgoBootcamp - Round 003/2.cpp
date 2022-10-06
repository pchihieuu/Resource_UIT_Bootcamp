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
const int N = 4e5 + 5;

int a[10], b[10];

set<int> s;

void solve(){
	
	int val = 53;
	sort(a + 1, a + 3 + 1);
	for(int i = 52; i >= 1; i--){
		b[3] = i;
		s.clear();
		for(int j = 1; j <= 3; j++){
			s.insert(a[j]);
			s.insert(b[j]);
		}
		if((int)s.size() < 6) continue;
		int check = 1;
		do{
			int cnt = 0;
			for(int j = 1; j <= 3; j++){
				if(b[j] > a[j]) cnt += 1;
				else cnt -= 1;
			}

			if(cnt <= 0) check = 0;
		}
		while(next_permutation(a + 1, a + 3 + 1));

		if(check) val = min(val, i);

	}

	if(val == 53) cout << -1 << '\n';
	else cout << val << '\n';
	
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> a[1] >> a[2] >> a[3] >> b[1] >> b[2]){
		if(a[1] == 0) return 0;
		solve();
	}

	
}