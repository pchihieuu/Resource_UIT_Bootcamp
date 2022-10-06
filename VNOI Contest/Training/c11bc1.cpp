#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> II;

const int INF = 1e9;
const int N = 1e5 + 5;

const int MOD = 790972;

int n, k;

II a[N];
int f[55][N];

vector<int> d[N];

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> n
	for(int i = 1; i <= n; i++){
		cin >> a[i].first >> a[i].second;
	}

	sort(a + 1, a + n + 1, [](II a, II b){
		return a.second < b.second;
	});

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			f[j][i] = (f[j - 1][i - 1] * a[i].first + f[j][i - 1]) % MOD;
		}
	}

	int res = f[k][n];

	int cnt = 0, x = a[1].second;
	for(int i = 1; i <= n; i++){
		if(a[i].second == x){
			d[cnt].push_back(a[i].first);
		}
		else{
			cnt += 1;
			d[cnt].push_back(a[i].first);
		}
	}

	for(int i = 0; i <= cnt; i++){
		for(int j = 0; j < (int)d[i].size(); j++){
			for(int x = 1; x <= k; x++){
				
			}
		}
	}

	cout << sum;



	
}