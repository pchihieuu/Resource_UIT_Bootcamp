#include<bits/stdc++.h>
using namespace std;


const int N = 5e3 + 5;

int n;
int a[N], b[N];

long long f[N][N];
long long val[N];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}

	for(int i = 1; i <= n; i++){
		val[i] = val[i - 1] + 1ll * a[i] * b[i];
	}

	for(int i = 1; i <= n; i++){
		f[i][i] = 1ll * a[i] * b[i];
	}

	for(int k = 2; k <= n; k++){
		for(int l = 1; l + k - 1 <= n; l++){
			int r = l + k - 1;
			f[l][r] = f[l + 1][r - 1] + 1ll * a[l] * b[r] + 1ll * a[r] * b[l];
		}
	}

	long long res = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			res = max(res, val[i - 1] + f[i][j] + (val[n] - val[j]));
		}
	}

	cout << res;

}