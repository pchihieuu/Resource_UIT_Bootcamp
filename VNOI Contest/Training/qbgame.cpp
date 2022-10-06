#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e4 + 5;
const int INF = 1e18;

int n;
int a[8 + 5][N];
int f[N][1 << 8];
vector<pair<int, int> > q;

int check1(int t){
	for(int i = 0; i < 8 - 1; i++){
		if((t >> i & 1) && (t >> (i + 1) & 1))
			return 0;
	}
	return 1;
}

int check2(int t1, int t2){
	if(!check1(t1) || !check1(t2)) return 0;
	for(int i = 0; i < 8; i++){
		if((t1 >> i & 1) &&  (t2 >> i & 1))
			return 0;
	}
	return 1;
}

int val(int col, int t){
	int ans = 0;
	for(int i = 0; i < 8; i++){
		if(t >> i & 1) ans += a[i + 1][col];
	}
	return ans;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	int ma = -INF;
	for(int i = 1; i <= 8; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			ma = max(ma, a[i][j]);
		}
	}

	for(int t1 = 0; t1 < (1 << 8); t1++){
		for(int t2 = 0; t2 < (1 << 8); t2++){
			if(check2(t1, t2)){
				q.push_back(make_pair(t1, t2));
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int t = 0; t < (1 << 8); t++){
			f[i][t] = -INF;
		}
	}

	for(int t = 0; t < (1 << 8); t++){
		if(check1(t)){
			f[1][t] = val(1, t);
		}
	}

	for(int i = 2; i <= n; i++){
		for(auto it: q){
			int t1 = it.first, t2 = it.second;
			f[i][t2] = max(f[i][t2], f[i - 1][t1] + val(i, t2));
		}
	}

	int res = -INF;
	for(int i = 0; i < (1 << 8); i++){
		if(check1(i))
			res = max(res, f[n][i]);
	}

	if(ma < 0) cout << ma;
	else cout << res;
}