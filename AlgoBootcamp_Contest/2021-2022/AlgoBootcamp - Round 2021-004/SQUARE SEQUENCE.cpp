#include<bits/stdc++.h>
using namespace std;

#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ld long double

typedef pair<int, int> II;
typedef pair<int, II> III;

/// 4 directions
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

/// Default long long max => 1e18
const int INF = 1e18;

/// Default MOD => 1e9 + 7
const int MOD = 1e9 + 7;

/// Input limit
const int N = 1e5 + 5;

int n, l;

int p(int a, int b){
    if(b == 0) return 1;
    if(b == 1) return a;
    int c = p(a, b / 2);
    c = (c * c) % MOD;
    if(b & 1) c = (c * a) % MOD;
    return c;
}

void solve(){
    cin >> n >> l;
    int val = (p(4, n + 1) - 1 + MOD) % MOD;
    int mau = p(3, MOD - 2);
    val = (val * mau) % MOD;

    l = (l * l) % MOD;

    val = (val * l) % MOD;
    cout << val;

}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T = 1;
	//cin >> T;
	while(T--){solve();}
}
