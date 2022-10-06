#include<bits/stdc++.h>
using namespace std;

//#define int long long

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
const int N = 4e5 + 5;

vector<int> a[N];
set<int> x[N];
int n, k;
int dd[N];

void solve(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        dd[i] = 0;
        x[i].clear();
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        x[u].insert(v);
        x[v].insert(u);
    }

    int res = n;

    queue<int> q, q2;
    for(int i = 1; i <= n; i++){
        if(x[i].size() == 1 || x[i].size() == 0){
            dd[i] = 1;
            res -= 1;
            q.push(i);
        }
    }

    k -= 1;
    for(int t = 1; t <= k; t++){
        if(res <= 0) break;
        while(q.size()){
            int u = q.front();
            q.pop();
            for(int v: x[u]){
                x[v].erase(u);

                if(x[v].size() <= 1){
                    if(dd[v] == 0) res -= 1;
                    dd[v] = 1;
                    q2.push(v);
                }
            }
            x[u].clear();
        }
        q = q2;
        while(q2.size()) q2.pop();
    }

    cout << res << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; while(T--)
    solve();
}
/*
6 2
1 2
2 3
3 4
2 5
5 6
*/
