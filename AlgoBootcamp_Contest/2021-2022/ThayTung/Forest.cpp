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
const int N = 5e5 + 5;

struct BIT{
    int n;
    vector<int> f;
    BIT(){}
    BIT(int n){
        this->n = n;
        init();
    }

    void init(){
        f = vector<int> (n + 5, 0);
    }

    void update(int x, int val){
        for(; x <= n; x += x&(-x))
            f[x] += val;
    }

    int get(int x){
        int ans = 0;
        for(; x >= 1; x -= x&(-x))
            ans += f[x];
        return ans;
    }
};

int n, m;
II a[N], q[N];
int L[N], R[N];
int ans[N];
vector<int> U[N], V[N], both[N];

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    for(int i = 1; i <= m; i++){
        cin >> q[i].fi >> q[i].se;
        U[q[i].fi].pb(i);
        V[q[i].se].pb(i);
    }

    // fall to the Left
    for(int i = 1; i <= n; i++){
        if(a[i].fi - a[i].se < a[1].fi){
            L[i] = -1;
            continue;
        }
        int p = i - 1;
        while(p >= 1 && a[i].fi - a[i].se < a[p].fi){
            if(a[p].fi + a[p].se <= a[i].fi) p -= 1;
            else p = L[p] - 1;
        }
        L[i] = p + 1;
    }

    // fall to the Right
    for(int i = n; i >= 1; i--){
        if(a[i].fi + a[i].se > a[n].fi){
            R[i] = n + 1;
            continue;
        }
        int p = i + 1;
        while(p <= n && a[i].fi + a[i].se > a[p].fi){
            if(a[p].fi - a[p].se >= a[i].fi) p += 1;
            else p = R[p] + 1;
        }
        R[i] = p - 1;
    }

    BIT f(n);
    for(int i = 1; i <= n; i++){
        if(L[i] >= 1) f.update(L[i], 1);
        for(int j: V[i]){
            int v = i, u = q[j].fi;
            ans[j] += f.get(v) - f.get(u - 1);
        }
    }

    f.init();
    for(int i = n; i >= 1; i--){
        if(R[i] <= n) f.update(R[i], 1);
        for(int j: U[i]){
            int u = i, v = q[j].se;
            ans[j] += f.get(v);
        }
    }

    for(int i = 1; i <= n; i++){
        if(1 <= L[i] && R[i] <= n) both[R[i]].pb(i);
    }

    f.init();
    for(int i = 1; i <= n; i++){
        for(int j: both[i]){
            f.update(L[j], 1);
        }
        for(int j: V[i]){
            int v = i, u = q[j].fi;
            ans[j] -= f.get(v) - f.get(u - 1);
        }
    }

    for(int i = 1; i <= m; i++){
        cout << ans[i] << '\n';
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
