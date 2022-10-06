#include<bits/stdc++.h>
using namespace std;

#define int long long

int k;
int n;
int a[505][505], s[505][505];
int f[505][505];

int get(int x1, int y1, int x2, int y2){
	return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

int dp(int l, int r, int clock){
	if(l < 1 || r < 1) return clock ^ 1;
	if(f[l][r] != -1) return f[l][r];
	int row = get(l, 1, l, r);
	int col = get(1, r, l, r);

	if(row % 2 == 0){
		int key = dp(l - 1, r, clock ^ 1);
		if(clock == key) return f[l][r] = clock;
	}

	if(col % 2 == 0){
		int key = dp(l, r - 1, clock ^ 1);
		if(clock == key) return f[l][r] = clock;
	}

	return f[l][r] = clock ^ 1;
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			f[i][j] = -1;
		}
	}

	int key = dp(n, n, 1);

	if(key == 1) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> k;
	while(k--){
		solve();
	}
}