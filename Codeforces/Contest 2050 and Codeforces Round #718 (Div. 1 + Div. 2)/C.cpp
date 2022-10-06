#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e9 + 5;

const int N = 500 + 5;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 1};

int n;
int p[N];
int a[N][N];

int val = 0;

void dfs(int u, int v, int col){
	a[u][v] = col;
	val -= 1;
	if(val == 0) return;
	for(int t = 0; t < 4; t++){
		if(val == 0) return;
		int i = u + dx[t];
		int j = v + dy[t];
		if(i < 1 || i > n || j < 1 || j > n || j > i) continue;
		if(a[i][j]) continue;
		dfs(i, j, col);
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	for(int i = n; i >= 1; i--){
		a[i][i] = p[i];
		val = p[i];
		dfs(i, i, p[i]);
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] != 0) cout << a[i][j] << " ";
		}
		cout << endl;
	}

	
}
