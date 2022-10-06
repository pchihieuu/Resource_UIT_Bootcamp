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
const int N = 2e5 + 5;

int n, k;
int a[N], b[N];

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; i++){
        if(i - 1 < k && i > n - k && a[i] != b[i]){
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';


}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T = 1;
	cin >> T;
	while(T--){solve();}
}
