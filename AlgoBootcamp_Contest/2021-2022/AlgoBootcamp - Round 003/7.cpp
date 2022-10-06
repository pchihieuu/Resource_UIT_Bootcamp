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
const int N = 1e3 + 5;

int n, m;

char a[N][N], b[N][N][5];
int d[5];

void solve(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}

	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m; j++){
			cin >> b[i][j][1];
		}
	}

	for(int i1 = 1, j2 = m; i1 <= m; i1++, j2 -= 1){
		for(int j1 = 1, i2 = 1; j1 <= m; j1++, i2 += 1){
			b[i1][j1][2] = b[i2][j2][1];
		}
	}

	for(int i1 = 1, j2 = m; i1 <= m; i1++, j2 -= 1){
		for(int j1 = 1, i2 = 1; j1 <= m; j1++, i2 += 1){
			b[i1][j1][3] = b[i2][j2][2];
		}
	}

	for(int i1 = 1, j2 = m; i1 <= m; i1++, j2 -= 1){
		for(int j1 = 1, i2 = 1; j1 <= m; j1++, i2 += 1){
			b[i1][j1][4] = b[i2][j2][3];
		}
	}

	for(int i = 1; i <= 4; i++) d[i] = 0;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int t = 1; t <= 4; t++){
				int check = 1;
				for(int u = 1; u <= m; u++){
					if(check == 0) break;
					for(int v = 1; v <= m; v++){
						int u1 = i + u - 1;
						int v1 = j + v - 1;
						if(u1 > n || v1 > n || b[u][v][t] != a[u1][v1]){
							check = 0;
							break;
						}
					}
				}
				if(check) d[t] += 1;
			}
		}
	}
	cout << d[1] << " ";
	for(int i = 4; i >= 2; i--) cout << d[i] << " ";
	cout << '\n';

}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m){
		if(n == 0) return 0;
		solve();
	}

	
}