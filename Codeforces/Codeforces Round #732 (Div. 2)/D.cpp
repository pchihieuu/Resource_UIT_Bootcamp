#include<bits/stdc++.h>
using namespace std;

#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e9;
const int MOD = 998244353;
const int N = 1e5 + 5;

int n;
int a[N];
int gt[N];

int pow(int a, int b){
	if(b == 0) return 1;
	if(b == 1) return a % MOD;
	int c = pow(a, b / 2);
	c = (c * c) % MOD;
	if(b & 1) c = (c * a) % MOD;
	return c;
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		char c; cin >> c;
		a[i] = c - '0';
	}

	int p = 0, z = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 0){
			z += 1;
		}
		else{
			if(a[i - 1]){
				p += 1;
				a[i] = a[i - 1] = 0;
			}
		}
	}

	int tu = gt[p + z];
	int mau = (gt[z] * gt[p]) % MOD;
	//Nghich dao Modulo
	int thuong = (tu * pow(mau, MOD - 2)) % MOD;
	cout << thuong << '\n';
}

void init(){
	gt[0] = 1;
	for(int i = 1; i < N; i++){
		gt[i] = (gt[i - 1] * i) % MOD;
	}
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	init();
	int T; cin >> T; while(T--){solve();}
}