#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> II;
typedef pair<II, int> III;

const int INF = 1e9;
const int N = 20 + 5;


int n;
int a[N][N];

II f[1 << 20];
vector<int> b[N];

int32_t main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}

	for(int i = 0; i < (1 << n); i++){
		int val = __builtin_popcount(i);
		b[val].push_back(i);
	}

	for(int i = 0; i < (1 << n); i++){
		f[i] = make_pair(-INF, 0);
	}
	f[0] = make_pair(0, 1);

	for(int i = 0; i < n; i++){
		for(int mask: b[i]){
			for(int j = 0; j < n; j++){
				if(mask >> j & 1) continue;
				int on = mask | (1 << j);
				int val = f[mask].first + a[i + 1][j + 1];
				if(f[on].first == val){
					f[on].second += f[mask].second;
				}
				if(f[on].first < val){
					f[on] = make_pair(val, f[mask].second);
				}
			}
		}
	}

	cout << f[(1 << n) - 1].first << " " << f[(1 << n) - 1].second;
}