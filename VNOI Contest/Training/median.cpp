#include<bits/stdc++.h>
using namespace std;

#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 250000 + 5;
const int L = 65535 + 1;

int seed, mul, add, n, k;
int a[N];

int it[4 * L];
int Case = 0;

void update(int id, int l, int r, int x, int val){
    if(x < l || r < x) return;
    if(l == r){
        it[id] += val;
        return;
    }
    int m = (l + r) / 2;
    update(id << 1, l, m, x, val);
    update(id << 1 | 1, m + 1, r, x, val);
    it[id] = it[id << 1] + it[id << 1 | 1];
}

int query(int id, int l, int r, int val){
    if(l == r) return l;
    int m = (l + r) >> 1;
    if(it[id << 1] >= val){ 
        return query(id << 1, l, m, val);
    }
    else{
        return query(id << 1 | 1, m + 1, r, val - it[id << 1]);
    }
}

void solve(){
    cin >> seed >> mul >> add >> n >> k;
    a[1] = seed;
    for(int i = 2; i <= n; i++){
        a[i] = (a[i - 1] * mul + add) % 65536;
    }

    for(int i = 1; i <= n; i++){
        a[i] += 1;
    }
  
    int res = 0;
    for(int i = 1; i < k; i++){
        update(1, 1, L, a[i], 1);
    }
   
    for(int i = k; i <= n; i++){
        update(1, 1, L, a[i], 1);
        int x = query(1, 1, L, (k + 1) / 2);
        res += x - 1;
        update(1, 1, L, a[i - k + 1], -1);
    }

    for(int i = n - k + 2; i <= n; i++){
        update(1, 1, L, a[i], -1);
    }
    cout << "Case #" << ++Case << ": " << res << '\n';
}
int32_t main(){
    //freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--){solve();}
    

    
}
/*
1
3 1 1 10 3
*/