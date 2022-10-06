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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int a[5][5], b[5][5];
map<int, int> m;

int mark(){
	int val = 1;
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			val = val * 10 + a[i][j];
		}
	}

	if(m.count(val)) return 1;
	m[val] = 1;
	return 0;
}

void solve(){
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			char c;
			cin >> c;
			a[i][j] = c - '0';
		}
	}

	m.clear();
	int ans = 0;
	while(1){
		for(int i = 1; i <= 3; i++){
			for(int j = 1; j <= 3; j++){
				b[i][j] = 0;
				for(int t = 0; t < 4; t++){
					int u = i + dx[t];
					int v = j + dy[t];
					if(u < 1 || u > 3 || v < 1 || v > 3) continue;
					b[i][j] += a[u][v];
				}
				b[i][j] %= 2;
			}
		}

		int check = 1;
		for(int i = 1; i <= 3; i++){
			for(int j = 1; j <= 3; j++){
				if(a[i][j] != b[i][j]) check = 0;
			}
		}

		if(check == 1) break;
		for(int i = 1; i <= 3; i++){
			for(int j = 1; j <= 3; j++){
				a[i][j] = b[i][j];
			}
		}
		int key = mark();
		if(key) break;
		ans += 1;
	}
	
	cout << ans - 1 << '\n';


}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}