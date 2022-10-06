#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int N = 4e2;

int n, M;

int c[N][N];
int gt[N];
int f[N];

int C(int k, int n){
	if(c[k][n] != -1) return c[k][n];
	if(n == k) return 1;
	if(k == 0) return 1;
	if(k == 1) return n;
	return c[k][n] = (C(k - 1, n - 1) + C(k, n - 1)) % M;
}




int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> M;

	for(int i = 0; i <= 400; i++){
		for(int j = 0; j <= 400; j++){
			c[i][j] = -1;
		}
	}

	f[1] = 1;
	gt[1] = 1;
	for(int i = 2; i <= 400; i++){
		f[i] = (f[i - 1] * 2) % M;
		gt[i] = (gt[i - 1] * i) % M;
	}
	int res = f[n];
	for(int i = 1; i <= n; i++){
		int kt = n  - 1 - 2 * i;
		int vt = i;
		kt = kt + vt;
		if(vt > kt) break;
		res += ((gt[n - i ]) * C(vt, kt)) % M;
	}

	cout << res;

}
