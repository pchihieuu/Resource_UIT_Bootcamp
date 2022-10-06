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
char a[N];
set<int> s;

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	s.clear();
	for(int i = 1; i <= n; i++){
		s.insert((a[i] - 'a' + 1));
		if(i <= n - 1)
			s.insert((a[i] - 'a' + 1) * 311 + (a[i + 1] - 'a' + 1));
		if(i <= n - 2)
			s.insert((a[i] - 'a' + 1) * 311 * 311 + (a[i + 1] - 'a' + 1) * 311 + (a[i + 2] - 'a' + 1));
	}

	for(char i = 'a'; i <= 'z'; i++){
		int val = i - 'a' + 1;
		if(s.count(val) == 0){
			cout << i << '\n';
			return;
		}
	}

	for(char i = 'a'; i <= 'z'; i++){
		for(char j = 'a'; j <= 'z'; j++){
			int val = (i - 'a' + 1) * 311 + (j - 'a' + 1);
			if(s.count(val) == 0){
				cout << i << j << '\n';
				return;
			}
		}
	}

	for(char i = 'a'; i <= 'z'; i++){
		for(char j = 'a'; j <= 'z'; j++){
			for(char k = 'a'; k <= 'z'; k++){
				int val = (i - 'a' + 1) * 311 * 311 + (j - 'a' + 1) * 311 + (k - 'a' + 1);
				if(s.count(val) == 0){
					cout << i << j << k << '\n';
					return;
				}
			}
		}
	}

}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}