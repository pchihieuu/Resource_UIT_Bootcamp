#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e9;
const int N = 2000 + 5;


int n;
int a[N];

int32_t main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			f[i][j] = INF;
		}
	}

	
}