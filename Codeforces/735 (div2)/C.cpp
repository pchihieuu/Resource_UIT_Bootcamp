#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 4e5 + 5;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while(T--){
        int n, m; cin >> n >> m;
        ++m;
        int ans = 0;
        for (int k = 30; k >= 0 and n < m; k--) {
            if ((n >> k & 1) == (m >> k & 1)) continue;
            if (m >> k & 1) ans |= 1 << k, n |= 1 << k;
        }
        cout << ans << '\n';
    }
}