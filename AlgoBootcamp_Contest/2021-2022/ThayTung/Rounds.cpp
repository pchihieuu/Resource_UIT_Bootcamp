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
    int k, n;
    cin >> n >> k;
    int ans1 = 0, ans2 = k;
    int x;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(ans2 == 0) ans2 = k;
        if(x > ans2) continue;
        if(x == ans2){
            ans2 = 0;
            ans1 += 1;
        }
        else{
            ans2 -= x;
        }
    }
    cout << ans1 << '\n' << ans2;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
