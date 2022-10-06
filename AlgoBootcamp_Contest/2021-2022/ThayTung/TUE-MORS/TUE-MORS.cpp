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

int backTrack(int col, int l, int r, int pos){
    if(l == r) return col;
    int mid = (l + r) / 2;
    if(pos <= mid) return backTrack(col, 1, mid, pos);
    else return backTrack(col ^ 1, 1, mid, pos - mid);
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> res;
    for(int i = 1; i <= k; i++){
        int pos = n + i - 1;
        for(int j = 0; j < 63; j++){
            int val = 1ll << j;
            if(val >= pos){
                res.push_back(backTrack(0, 1, val, pos));
                break;
            }
        }
    }
    for(int i: res) cout << i;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("out.txt", "w", stdout);
    //int T; cin >> T; while(T--)
    solve();
}
