#include<bits/stdc++.h>
using namespace std;

//#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 400 + 5;

int n, m, k;
int a[N][N];
int s[30][N][N];

int sum(int t, int i1, int j1, int i2, int j2){
	return s[t][i2][j2] - s[t][i1 - 1][j2] - s[t][i2][j1 - 1] + s[t][i1 - 1][j1 - 1];
}

int check(int i1, int j1, int i2, int j2){
	int val = 0;
	for(int t = 0; t < 26; t++){
		if(sum(t, i1, j1, i2, j2)) val += 1;
	}
	return val;
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int T; cin >> T; while(T--){solve();}

	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			char x;
			cin >> x;
			a[i][j] = x - 'A';
			for(int t = 0; t < 26; t++){
				s[t][i][j] = s[t][i - 1][j] + s[t][i][j - 1] - s[t][i - 1][j - 1];
				if(t == a[i][j]){
					s[t][i][j] += 1;
				}
			}
		}
	}

	int64_t res = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			int l1 = 1, l2 = 1;
			for(int r = 1; r <= m; r++){
				while(l1 < r && check(i, l1, j, r) > k){
					l1 += 1;
				}
				l2 = max(l2, l1);
				while(l2 < r && check(i, l2 + 1, j, r) == k){
					l2 += 1;
				}
				
				if(check(i, l1, j, r) == k)	res += (l2 - l1 + 1);
			}
		}		
	}

	cout << res << endl;
}