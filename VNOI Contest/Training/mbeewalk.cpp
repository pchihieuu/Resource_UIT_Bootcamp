#include<bits/stdc++.h>
using namespace std;

int dx[] = {0, -1, -1, 0, 1, 1};
int dy[] = {2, 1, -1, -2, -1, 1};

int X = 50, Y = 50;
int f[100][100][100];

int dp(int k, int x, int y){
	if(k == 0){
		if(x != X || y != Y) return 0;
		return 1;
	}
	if(f[k][x][y] != -1) return f[k][x][y];

	int res = 0;
	for(int i = 0; i < 6; i++){
		res += dp(k - 1, x + dx[i], y + dy[i]);
	}

	return f[k][x][y] = res;
}

int main(){
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			for(int t = 0; t < 100; t++){
				f[i][j][t] = -1;
			}
		}
	}

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << dp(n, 50, 50) << endl;
	}
}