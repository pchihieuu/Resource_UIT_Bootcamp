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
const int N = 1e6 + 5;

string s, t;
int ns, nt;
vector<int> pref, suff, next_diff;

void solve(){
    cin >> s >> t;
    ns = s.size(), nt = t.size();

    next_diff = vector<int> (nt, 2 * nt);
    for(int i = nt - 2; i >= 0; i--){
        if(t[i] != t[i + 1]){
            next_diff[i] = i + 1;
        }
        else{
            next_diff[i] = next_diff[i + 1];
        }
    }

    pref = vector<int> {0};
    for(int i = 0; i < ns; i++){
        int pos = pref.back();
        while(pos < nt && t[pos] != s[i]) pos++;
        pos++;
        pref.pb(pos);
    }

    suff = vector<int> {nt - 1};
    for(int i = ns - 1; i >= 0; i--){
        int pos = suff.back();
        while(0 <= pos && t[pos] != s[i]) pos--;
        pos--;
        suff.pb(pos);
    }
    for(int i = 0; i < pref.size() - 1; i++){
        cout << pref[i] << " ";
    }
    cout << endl;
    for(int i = suff.size() - 2; i >= 0; i--){
        cout << suff[i] << " ";
    }
    cout << endl;
    int ans1;
    char ans2;

    for(int i = 0; i < ns; i++){
        cout << i << " " << pref[i] << " " << suff[ns - i - 1] << " " << ns - i -1 << endl;
        if(pref[i] <= suff[ns - i - 1]){
            if(t[pref[i]] != s[i]){
                ans1 = i + 1;
                ans2 = t[pref[i]];
                break;
            }
            int pos = next_diff[pref[i]];
            if(pos <= suff[ns - i - 1]){
                ans1 = i + 1;
                ans2 = t[pos];
                break;
            }
        }
    }

    cout << ans1 << " " << ans2;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
