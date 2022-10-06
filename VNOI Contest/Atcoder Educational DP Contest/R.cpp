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
typedef vector<int> VI;
typedef vector<VI> VII;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

VII operator * (VII a, VII b){
    int n = a.size(), p = a[0].size(), m = b[0].size();
    VII c(n, VI(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < p; k++){
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= MOD;
            }
        }
    }
    return c;
}

VII power_matrix (VII a, int b){
    if(b == 1) return a;
    VII c = power_matrix(a, b / 2);
    c = (c * c);
    if(b & 1) c = (c * a);
    return c;
}

int n, k;
VII a;

void solve(){
    cin >> n >> k;
    a = VII(n, VI(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    a = power_matrix(a, k);

    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum = (sum + a[i][j]) % MOD;
        }
    }
    cout << sum;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
