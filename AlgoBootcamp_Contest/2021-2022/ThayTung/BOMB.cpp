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
    map<int, int> m;
    vector<int> a(n, 0);

    for(int &i: a){
        cin >> i;
        m[i] += 1;
    }

    int res = 0, val = 0;
    for(auto i: m){

        if(i.fi + i.fi == k){
            val += m[i.fi] - 1;
        }
        else{
            res += min(m[i.fi], m[k - i.fi]);
        }
    }

    res = res / 2;
    cout << res + val;

}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
