#include<bits/stdc++.h>
using namespace std;

#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ld long double
#define cc cout<<"CC"<<endl;

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

int n, h;


void solve(){
    cin >> n >> h;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    sort(a.begin(), a.end());
    int val = a[n - 2] + a[n - 1];
    int val2 = h / val;
    if(val2 * val < h) val2 += 1;
    if(val2 > 0 && (val2 - 1) * val + a[n - 1] >= h){
        cout << val2 * 2 - 1 << '\n';
    }
    else cout << val2 * 2 << '\n';

}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T = 1;
	cin >> T;
	while(T--){solve();}
}
