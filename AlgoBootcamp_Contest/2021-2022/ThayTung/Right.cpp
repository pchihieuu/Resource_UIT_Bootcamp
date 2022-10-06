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


int x[100];
II d[4];
char D[4];

const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e3 + 5;

int n, m;
int U1, V1, U2, V2;
char a[N][N];
int ans[4][N][N];

int check(int u, int v){
    if(u < 1 || u > n || v < 1 || v > m) return 0;
    if(a[u][v] == '#') return 0;
    return 1;
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'D'){
                U2 = i;
                V2 = j;
            }
            if(a[i][j] == 'E' || a[i][j] == 'S' || a[i][j] == 'W' || a[i][j] == 'N'){
                U1 = i;
                V1 = j;
            }
        }
    }
    x['E'] = 0, x['S'] = 1, x['W'] = 2, x['N'] = 3;
    D[0] = 1; d[0] = {0, 1};
    D[1] = 2; d[1] = {1, 0};
    D[2] = 3; d[2] = {0, -1};
    D[3] = 0; d[3] = {-1, 0};

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 0; k < 4; k++){
                ans[k][i][j] = INF;
            }
        }
    }
    ans[x[a[U1][V1]]][U1][V1] = 0;
    queue<III> q;
    q.push(mp(x[a[U1][V1]], mp(U1, V1)));
    while(q.size()){
        int direct = q.front().fi;
        int u = q.front().se.fi, v = q.front().se.se;
        q.pop();
        if(u == U2 && v == V2){
            cout << ans[direct][u][v] << '\n';
            return;
        }

        // Go straight
        int u1 = u + d[direct].fi, v1 = v + d[direct].se;
        if(check(u1, v1) && ans[direct][u1][v1] > ans[direct][u][v] + 1){
            ans[direct][u1][v1] = ans[direct][u][v] + 1;
            q.push(mp(direct, mp(u1, v1)));
        }

        // Turn right
        int right = D[direct];
        u1 = u + d[right].fi, v1 = v + d[right].se;
        if(check(u1, v1) && ans[right][u1][v1] > ans[direct][u][v] + 1){
            ans[right][u1][v1] = ans[direct][u][v] + 1;
            q.push(mp(right, mp(u1, v1)));
        }
    }
	cout << -1;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("C:\\users\\nqhho\\Desktop\\input6.txt", "r", stdin);
    //int T; cin >> T; while(T--)
    solve();
}
