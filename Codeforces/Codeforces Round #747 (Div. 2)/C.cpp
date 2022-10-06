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
const int N = 3e5 + 5;

int n;
char c;
char a[N];
set<II> s;

vector<int> nt;

void solve(){
    cin >> n >> c;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int val = 1;
    for(int i = 0; i < nt.size(); i++){
        if(nt[i] <= n) val = nt[i];
        else{
            break;
        }
    }
    int kt = 1;
    for(int i = 1; i <= n; i++){
        if(a[i] != c){
            kt = 0;
            break;
        }
    }
    if(kt){
        cout << 0 << '\n';
        return;
    }
    for(int i = 2; i <= n; i++){
        int check = 1;
        for(int j = i; j <= n; j += i){
            if(a[j] != c){
                check = 0;
                break;
            }
        }
        if(check){
            cout << 1 << '\n';
            cout << i << '\n';
            return;
        }
    }

    cout << 2 << '\n';
    cout << 2 << " " << val << '\n';
}

int mark[N];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    mark[0] = mark[1] = 1;
    for(int i = 2; i*i < N; i++) {
        if (!mark[i]) {
            for(int j = i*i; j < N; j+=i) {
                mark[j] = 1;
            }
        }
    }
    for(int i = 2; i < N; i++){
        if(!mark[i]) nt.pb(i);
    }


    int T; cin >> T; while(T--)
    solve();
}
