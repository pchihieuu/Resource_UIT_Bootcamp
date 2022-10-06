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

void solve(){
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    int mx = *max_element(a + 1, a + n + 1);
    int mn = *min_element(a + 1, a + n + 1);

    if(n == 2 && a[1] != a[2]){
        cout << -1;
        return;
    }

    if((n & 1) == 0 && (sum & 1)){
        cout << -1;
        return;
    }

    int h = (sum - 2 * mn + n - 3) / (n - 2);

    if(h < mx) h = mx;
    if((h * n - sum) & 1) h += 1;cout << h << endl;
    cout << (h * n - sum) / 2;
}


int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
