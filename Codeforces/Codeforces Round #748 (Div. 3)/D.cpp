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

int n;
int a[N];
int x[N];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = n / 2; i <= n; i++){
        if(a[i] == a[i - n / 2 + 1]){
            cout << -1 << '\n';
            return;
        }
    }
    int res = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            x[j] = abs(a[i] - a[j]);
        }
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(k == j) continue;
                int val = __gcd(x[j], x[k]);
                int cnt = 0;
                for(int t = 1; t <= n; t++){
                    if(__gcd(x[t], val) == val) cnt += 1;
                }
                if(cnt >= n / 2){
                    res = max(res, val);
                }
            }
        }
    }
    cout << res << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; while(T--)
    solve();
}
