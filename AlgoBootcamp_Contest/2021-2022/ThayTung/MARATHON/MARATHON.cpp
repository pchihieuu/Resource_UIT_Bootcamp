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



void solve(){
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        int a, b;
        char c;
        cin >> a >> c >> b;
        sum += a * 60 + b;
    }
    int res_s = sum % 60;
    int res_m = (sum / 60) % 60;
    int res_h = sum / 3600;
    cout << setw(2) << setfill('0') << res_h << ":";
    cout << setw(2) << setfill('0') << res_m << ":";
    cout << setw(2) << setfill('0') << res_s;

}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
/**
3
12:34
23:45
34:56
*/
