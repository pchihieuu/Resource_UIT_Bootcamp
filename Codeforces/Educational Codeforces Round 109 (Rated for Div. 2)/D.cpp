#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
int n;
vector<int> a, b;
int f[N][N];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	a.push_back(0);
	b.push_back(0);
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(x){
			a.push_back(i);
		}
		else{
			b.push_back(i);
		}
	}

	n = a.size() - 1;
	int m = b.size() - 1;

	for(int i = 1; i <= n; i++){
		f[i][0] = 1e9;
		for(int j = 1; j <= m; j++){
			f[i][j] = min(f[i][j - 1], f[i - 1][j - 1] + abs(a[i] - b[j]));
		}
	}

	cout << f[n][m];
	
}
/*
10
0 0 0 1 1 1 0 0 1 1
*/