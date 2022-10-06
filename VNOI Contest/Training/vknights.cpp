#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> II;

int n;
int a[105];
II f[105][1 << 3][1 << 3];

int cnt(int t){
	int ans = 0;
	for(int i = 0; i < 3; i++){
		if(t >> i & 1) ans += 1;
	}
	return ans;
}

int check2(int col1, int col2, int t1, int t2){
	for(int i = 0; i < 3; i++){
		if((t1 >> i & 1) && a[col1] - 1 == i)
			return 0;
		if((t2 >> i & 1) && a[col2] - 1 == i)
			return 0;
	}
	if((t1 >> 0 & 1) && (t2 >> 2 & 1)) return 0;
	if((t1 >> 2 & 1) && (t2 >> 0 & 1)) return 0;
	return 1;
}

int check3(int col1, int col2, int col3, int t1, int t2, int t3){
	if(check2(col1, col2, t1, t2) == 0) return 0;
	if(check2(col2, col3, t2, t3) == 0) return 0;

	if((t1 >> 0 & 1) && (t3 >> 1 & 1)) return 0;
	if((t1 >> 1 & 1) && (t3 >> 2 & 1)) return 0;
	if((t3 >> 0 & 1) && (t1 >> 1 & 1)) return 0;
	if((t3 >> 1 & 1) && (t1 >> 2 & 1)) return 0;

	return 1;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	if(n == 1){
		cout << 3 - (a[1] >= 1) << " " << 1 << endl;
		return 0;
	}


	for(int t1 = 0; t1 < (1 << 3); t1++){
		for(int t2 = 0; t2 < (1 << 3); t2++){
			if(check2(1, 2, t1, t2)){
				f[2][t1][t2] = make_pair(cnt(t1) + cnt(t2), 1);
			}
		}
	}

	for(int i = 3; i <= n; i++){
		for(int t1 = 0; t1 < (1 << 3); t1++){
			for(int t2 = 0; t2 < (1 << 3); t2++){
				for(int t3 = 0; t3 < (1 << 3); t3++){
					if(check3(i - 2, i - 1, i, t1, t2, t3)){

						if(f[i][t2][t3].first == f[i - 1][t1][t2].first + cnt(t3)){
							f[i][t2][t3].second += f[i - 1][t1][t2].second;
						}
						if(f[i][t2][t3].first < f[i - 1][t1][t2].first + cnt(t3)){
							f[i][t2][t3].first = f[i - 1][t1][t2].first + cnt(t3);
							f[i][t2][t3].second = f[i - 1][t1][t2].second;
						}
					}	
				}
			}
		}
	}

	II res = make_pair(0, 0);

	for(int t1 = 0; t1 < (1 << 3); t1++){
		for(int t2 = 0; t2 < (1 << 3); t2++){
			if(res.first == f[n][t1][t2].first){
				res.second += f[n][t1][t2].second;
			}
			if(res.first < f[n][t1][t2].first){
				res.first = f[n][t1][t2].first;
				res.second = f[n][t1][t2].second;
			}
		}
	}

	cout << res.first << " " << res.second;
}