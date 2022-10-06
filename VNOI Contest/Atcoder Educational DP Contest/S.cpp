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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

string k;
int d;

int dp[10004][102];

void solve(){
    cin >> k;
    cin >> d;

    dp[k.size()][0] = 1;
    for(int i = k.size() - 1; i >= 0; i--){
        for(int j = 0; j < d; j++){
            for(int digit = 0; digit < 10; digit++){
                dp[i][j] += dp[i + 1][(j - digit + 10 * d) % d];
                dp[i][j] %= MOD;
            }
        }
    }

    int res = 0;
    int sum = 0;

    for(int i = 0; i < k.size(); i++){
        for(int j = 0; j < (k[i] - '0'); j++){
            int val = d - ((sum + j) % d);
            val %= d;
            res += dp[i + 1][val];
        }
        sum += k[i] - '0';
        sum %= d;
    }

    if(sum == 0) res += 1;
    res -= 1;

    cout << (res + MOD) % MOD;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
