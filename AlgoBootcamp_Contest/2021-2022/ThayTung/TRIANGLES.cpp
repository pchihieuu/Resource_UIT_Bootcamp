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
const int N = 3e5 + 5;

int a[N];
int s[2 * N];
int n, L;


void solve(){
    cin >> n >> L;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += 1;
    }
    sort(a + 1, a + n + 1);

    for(int i = n + 1; i <= 2 * n; i++){
        a[i] = a[i - n] + L;
    }
    a[2 * n + 1] = INF;

    int res = (n * (n - 1) * (n - 2)) / 6;

    int j = 1;
    for(int i = 1; i <= n; i++){
        while(2 * (a[j] - a[i]) < L) j += 1;
        int t = j - i - 1;
        res -= (t * (t - 1)) / 2;
    }
    cout << res;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
/**
10 10
0 1 2 3 4 5 6 7 8 9
*/
