#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, k;
char a[N], b[N];
int res;

int distance(int pos){
	int val = 0;
	for(int i = pos, j = 1; j <= m; j++, i++){
		if(i > n) i -= n;
		if(a[i] != b[j]) val += 1;
	}
	return val;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	res = m;
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= m; j++){
			cin >> b[j];
		}
		for(int j = 1; j <= n; j++){
			res = min(res, distance(j));
		}
	}

	cout << res;
}