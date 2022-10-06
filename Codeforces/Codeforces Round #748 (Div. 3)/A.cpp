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
    vector<int> a(3);
    int x, y, z;
    cin >> x >> y >> z;
    a[0] = x, a[1] = y, a[2] = z;
    sort(a.begin(), a.end());
    int mx = a[2] + 1;
    if(a[2] > a[1]){
        if(x == a[2]) x += 1;
        if(y == a[2]) y += 1;
        if(z == a[2]) z += 1;
    }

    cout << mx - x << " " << mx - y << " " << mx - z << '\n';

}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; while(T--)
    solve();
}
