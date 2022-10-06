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
        int n, k; cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        long long ans = -1e12;
        int l = max(1, n - 2 * k);
        for (int i = l; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
                ans = max(ans, 1LL * i * j - 1LL * k * (a[i] | a[j]));
            }
        }
        cout << ans << '\n';
    }
}