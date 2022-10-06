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
const int N = 1e2 + 5;

int n;
int d[N];
int mark[N];
int dp[1000006];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }

    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += d[i];
    }

    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = sum - d[i]; j >= 0; j--){
            if(dp[j]){
                dp[j + d[i]] = 1;
            }
        }
    }
    int res = 0;
    int cnt = 0;
    for(int i = 1; i <= sum; i++){
        if(dp[i]){
            res += i;
            cnt += 1;
        }
    }
    res = res * 2 + 1;
    res -= (cnt * (cnt - 1)) / 2;

    cout << res << endl;
}

void sol_ThayTung(){
    int n;
    cin >> n;
    vector<int> mas(n);
    int64_t s = 0;
    for(int &x: mas){
        cin >> x;
        s += x;
    }
    sort(mas.begin(), mas.end());

    vector<int> dp(s + 1, 0);
    s = 0;
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = s; j >= 0; j--){
            if(dp[j]) dp[j + mas[i]] = 1;
        }
        s += mas[i];
    }
    int cnt = 0;
    int64_t ans = 0;
    for(int i = s; i >= 0; i--){
        if(dp[i]){
            cnt += 1;
            ans += s + 1 - i;
        }
        else ans += cnt;
    }
    cout << ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
    //sol_ThayTung();
}
/**
7
8 2 6 3 8 3 9
*/
