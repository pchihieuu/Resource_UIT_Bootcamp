#include<bits/stdc++.h>

using namespace std;
#define int long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef pair<int, int >ii;
typedef pair<int, ii> iii;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
bool kiemtra(int k) {
    if (k == 0) return false;
    if ((int)sqrt(k) * (int)sqrt(k) == k) return true;
    return false;
}
void solve() {
    int a, b;
    cin >> a >> b;
    int c1 = a * a + b * b;
    int c2 = max(a, b) * max(a, b) - min(a, b) * min(a, b);
    cout << (kiemtra(c1) || kiemtra(c2)) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }


}
