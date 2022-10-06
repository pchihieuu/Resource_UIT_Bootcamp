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

int n, k;
int mark[20];
II td[20];
vector<int> g[20];
int res = 1e9;

II median[1 << 14];


int kc(II a, II b){
    return abs(a.fi - b.fi) + abs(a.se - b.se);
}

II tam(vector<int> O){
    int sz = O.size();
    vector<int> Ox, Oy;
    for(int i: O){
        Ox.pb(td[i].fi);
        Oy.pb(td[i].se);
    }
    sort(Ox.begin(), Ox.end());
    sort(Oy.begin(), Oy.end());
    return mp(Ox[sz / 2], Oy[sz / 2]);
}

void check(){
    int ans = 0;
    for(int i = 1; i <= k; i++){
        //cout << "Group " << i << ": ";
        int val = 0;
        for(int j: g[i]){
            val += 1 << (j - 1);
        }
        II O = median[val];
        for(int j: g[i]){
            ans += kc(O, td[j]);
        }
        //cout << endl;
    }
    res = min(res, ans);
}

int cnt = 0;
void ql(int group){

    if(group > k) return;

    int bd = 1;
    if(g[group].size()) bd = g[group].back() + 1;
    else{
        bd = g[group - 1].front() + 1;
    }

    for(int i = bd; i <= n; i++){
        if(mark[i]) continue;
        mark[i] = 1;
        cnt += 1;
        g[group].push_back(i);
        if(group == k && cnt == n){
            check();
        }
        else{
            ql(group);
            ql(group + 1);
        }

        mark[i] = 0;
        cnt -= 1;
        g[group].pop_back();
    }
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> td[i].fi >> td[i].se;
    }

    if(k >= n){
        cout << 0;
        return;
    }

    for(int t = 1; t < (1 << n); t++){
        vector<int> temp;
        for(int j = 0; j < n; j++){
            if(t >> j & 1){
                temp.push_back(j + 1);
            }
        }
        median[t] = tam(temp);
    }

    g[0].push_back(0);
    ql(1);

    cout << res;
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T = 1;
	//cin >> T;
	while(T--){solve();}
}

/*
4 1

0 0

0 4

4 0

4 4


*/
