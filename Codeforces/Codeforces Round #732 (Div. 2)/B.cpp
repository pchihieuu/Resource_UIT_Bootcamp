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
const int MOD = 1e9 + 7;
const int N = 4e5 + 5;

int pow(int a, int b){
	if(b == 0) return 1;
	if(b == 1) return a % MOD;
	int c = pow(a, b / 2);
	c = (c * c) % MOD;
	if(b & 1) c = (c * a) % MOD;
	return c;
}

int gt[1000];

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);

	gt[0] = 1;
	for(int i = 1; i <= 100; i++){
		gt[i] = gt[i - 1] * i;
		gt[i] %= MOD;
	}

	

	cout << (gt[8] * pow((gt[3] * gt[8 - 3]) % MOD, MOD - 2)) % MOD << '\n';



	
}