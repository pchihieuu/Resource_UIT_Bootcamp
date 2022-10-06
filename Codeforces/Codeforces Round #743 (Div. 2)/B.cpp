#include<bits/stdc++.h>
using namespace std;

#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n;
int a[N], b[N], p[N];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        p[b[i]] = i;
    }

    for(int i = 2 * n - 2; i >= 2; i -= 2){
        p[i] = min(p[i], p[i + 2]);
    }


    int res = n + 1;
    for(int i = 1; i <= n; i++){
        int val = (i - 1) + (p[a[i] + 1] - 1);
        res = min(res, val);
    }
    cout << res << '\n';
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}
}
