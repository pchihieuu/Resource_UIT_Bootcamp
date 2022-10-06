#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 2e3 + 5;

int n;
int a[N], s[N];

int f[N][N], k[N][N];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			f[i][j] = 0;
		}
	}

	for(int i = 1; i <= n; i++){
		k[i][i] = i;
	}
	

	for(int kc = 1; kc <= n; kc++){
		for(int l = 1; l <= n; l++){
			int r = l + kc - 1;
			if(r > n) break;

			for(int m = k[l][r - 1]; m <= k[l + 1][r]; m++){
				int val = min(s[m] - s[l - 1] + f[l][m], s[r] - s[m] + f[m + 1][r]);
				if(f[l][r] < val){
					f[l][r] = val;
					k[l][r] = m;
				}				
			}
		}
	}

	cout << f[1][n];
}