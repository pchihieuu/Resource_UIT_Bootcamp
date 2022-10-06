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
vector<int> a[N];
int d[N];
int cnt[50];
int XX;
int dem;

void dfs(int u, int p){
    for(int v: a[u]){
        if(v == p) continue;
        dfs(v, u);
        d[u] = d[u] ^ d[v];
    }
    if(d[u] == XX){
        d[u] = 0;
        dem += 1;
        //cout << u << endl;
    }
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        a[i].clear();
    }
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(int i = 0; i < 32; i++){
        cnt[i] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int t = 0; t < 32; t++){
            if(d[i] >> t & 1) cnt[t] += 1;
        }
    }
    int val = 0;
    int check = 0;
    for(int i = 0; i < 32; i++){
        if(cnt[i] % 2 == 0) continue;
        check = 1;

        if(val == 0){
            val = cnt[i];
        }
        else{
            val = min(val, cnt[i]);
        }
    }

    if(val == 1){
        cout << "NO" << '\n';
        return;
    }

    if(check == 0){
        cout << "YES" << '\n';
        return;
    }

    XX = 0;
    for(int i = 0; i < 32; i++){
        if(cnt[i] % 2){
            XX += 1ll << i;
        }
    }


    dem = 0;
    dfs(1, 1);

    //cout << dem << endl;
    while(dem > k){
        dem -= 2;
    }

    if(d[1] != 0 || dem < 2){
        cout << "NO" << '\n';
        return;
    }
    else{
        cout << "YES" << '\n';
        return;
    }

}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T = 1;
	cin >> T;
	while(T--){solve();}
}

/*
206683326 435543150 514117915 161349195 479545068 479613837 128874544
*/
