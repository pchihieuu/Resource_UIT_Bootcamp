#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int> > a;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	a = vector<vector<int> > (n + 5, vector<int> (m + 5, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}

	int res = 1e9;
	for(int i = 1; i <= n - 2; i++){
		for(int j = 1; j <= m - 2; j++){
			int sum = 0;
			for(int u = i; u <= i + 2; u++){
				for(int v = j; v <= j + 2; v++){
					sum += a[u][v];
				}
			}
			res = min(res, sum);
		}
	}
	cout << res;

}