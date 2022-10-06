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

/// 4 directions
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

/// Default long long max => 1e18
const int INF = 1e18;

/// Default MOD => 1e9 + 7
const int MOD = 1e9 + 7;

/// Input limit
const int N = 1e5 + 5;

int n, t;
II a[N];
vector<II> x;

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> t;
	for(int i = 1; i <= t; i++){
        cin >> a[i].fi >> a[i].se;
        x.push_back(mp(a[i].fi, -i));
        x.push_back(mp(a[i].se + 1, i));
	}
	sort(x.begin(), x.end());

    if(n == 0){
        cout << 0;
        return 0;
    }

    int ans = x[0].fi - 1 + n - x.back().fi + 1;
    int cnt = 1;
    int pos = x[0].fi;
	for(int i = 1; i < x.size(); i++){
        int val = x[i].fi - x[i - 1].fi;
        if(cnt % 3 == 0) ans += val;
        pos = x[i].fi;
        if(x[i].se < 0) cnt += 1;
        else cnt -= 1;
	}

	cout << ans;

}
