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
const int N = 2e5 + 5;

int n;
int p[N];


void solve(){
    cin >> n;
    cout << p[n] << '\n';
}

int32_t main(){
	p[1] = 1;
	for(int i = 2; i < N; i++){
        p[i] = ((p[i - 1] * (i * 2)) % MOD * (i * 2 - 1)) % MOD;
	}
	int T;
	cin >> T;
	while(T--){solve();}
}
