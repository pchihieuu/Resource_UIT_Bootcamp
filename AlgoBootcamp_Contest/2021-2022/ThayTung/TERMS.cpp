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
    int n, k;
    cin >> n >> k;
    int sum = (k * (k + 1)) / 2;
    if(n < sum){
        cout << -1;
        return;
    }

    int val = n - sum;
    cout << val + k << endl;
    for(int i = 1; i <= val; i++) cout << 1 << " ";
    for(int i = 1; i <= k; i++) cout << i << " ";
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
