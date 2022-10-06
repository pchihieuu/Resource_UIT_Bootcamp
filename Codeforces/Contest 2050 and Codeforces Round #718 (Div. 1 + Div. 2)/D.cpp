#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e18 + 5;

const int N = 500 + 5;

int n, m, k;
vector<III> a[N][N];

int f[25][N][N];


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j < m; j++){
			int x;
			cin >> x;
			a[i][j].push_back(mp(x, mp(i, j + 1)));
			a[i][j + 1].push_back(mp(x, mp(i, j)));
		}
	}

	for(int i = 1; i < n; i++){
		for(int j = 1; j <= m; j++){
			int x;
			cin >> x;
			a[i][j].push_back(mp(x, mp(i + 1, j)));
			a[i + 1][j].push_back(mp(x, mp(i, j)));
		}
	}

	if(k % 2 == 1){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cout << -1 << " ";
			}
			cout << endl;
		}
		return 0;
	}
	k /= 2;

	for(int t = 1; t <= k; t++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				f[t][i][j] = INF;
			}
		}
	}

	for(int t = 1; t <= k; t++){
		for(int u = 1; u <= n; u++){
			for(int v = 1; v <= m; v++){
				for(int i = 0; i < (int)a[u][v].size(); i++){
					int x = a[u][v][i].se.fi, y = a[u][v][i].se.se;
					int w = a[u][v][i].fi;
					f[t][x][y] = min(f[t][x][y], f[t - 1][u][v] + 2 * w);

				}
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << f[k][i][j] << " ";
		}
		cout << endl;
	}
}
