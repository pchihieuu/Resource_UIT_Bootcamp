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

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 300 + 5;

int n, m;
char a[N][N];
int sx, sy;
string s;

vector<II> pos[30];

int d[N][N][N];

void solve(){
    cin >> n >> m;
    cin >> sx >> sy;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            pos[a[i][j] - 'a'].pb(mp(i, j));
        }
    }
    cin >> s;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                d[i][j][k] = INF;
            }
        }
    }

    queue<II> q;
    q.push(mp(sx, sy));
    d[0][sx][sy] = 0;
    while(q.size()){
        int u = q.front().fi, v = q.front().se;
        q.pop();
        for(int t = 0; t < 4; t++){
            int x = u + dx[t];
            int y = v + dy[t];
            if(x < 1 || x > n || y < 1 || y > m) continue;
            if(d[0][x][y] > d[0][u][v] + 1){
                d[0][x][y] = d[0][u][v] + 1;
                q.push(mp(x, y));
            }
        }

    }

    for(int i = 0; i < s.size(); i++){
        int p = i + 1;
        int c = s[i] - 'a';
        for(auto [u, v]: pos[c]){
            d[p][u][v] = d[p - 1][u][v];
            q.push(mp(u, v));
        }
        while(q.size()){
            int u = q.front().fi, v = q.front().se;
            q.pop();
            for(int t = 0; t < 4; t++){
                int x = u + dx[t];
                int y = v + dy[t];
                if(x < 1 || x > n || y < 1 || y > m) continue;
                if(d[p][x][y] > d[p][u][v] + 1){
                    d[p][x][y] = d[p][u][v] + 1;
                    q.push(mp(x, y));
                }
            }
        }
    }

    int res = INF;
    int e = s.back() - 'a';
    for(auto [u, v]: pos[e]){
        res = min(res, d[(int)s.size()][u][v]);
    }

    cout << res << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
