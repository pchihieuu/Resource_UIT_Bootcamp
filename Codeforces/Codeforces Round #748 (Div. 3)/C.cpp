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
const int N = 4e5 + 5;

int n, k;
int a[N];

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        cin >> a[i];
    }
    sort(a + 1, a + k + 1);
    int cat = 0;
    int res = 0;
    for(int i = k; i >= 1; i--){
        if(cat + n - a[i] >= n){
            break;
        }
        cat = cat + n - a[i];
        //cout << cat << endl;
        res += 1;
    }
    cout << res << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; while(T--)
    solve();
}
