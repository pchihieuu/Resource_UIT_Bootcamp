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
const int N = 1e5 + 5;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    if(a == 1){
        if((n - 1) % b == 0){
            cout << "Yes" << '\n';
        }
        else cout << "No" << '\n';
        return;
    }

    int val = 1;
    
    while(val <= n){
        if((n - val) % b == 0){
            cout << "Yes" << '\n';
            return;
        }
        val *= a;
    }
 
    cout << "No" << '\n';
}


int32_t main(){
    //freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--){solve();}

    
}
/*
1
19260817 233 264
*/