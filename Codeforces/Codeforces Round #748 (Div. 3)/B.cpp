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
const int N = 1e5 + 5;



void solve(){
    string s;
    cin >> s;

    int res = s.size();
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0') res -= 1;
    }

    //00
    int kq1 = INF;
    int cnt = 0;
    int i = s.size() - 1;
    for(; i >= 0; i--){
        if(s[i] == '0'){
            cnt += 1;
        }
        if(cnt == 2){
            kq1 = i;
            break;
        }
    }
    if(kq1 < s.size())
    res = min(res, (int)s.size() - kq1 - 2);

    //25
    int kq2 = INF;
    int check = 0;
    i = s.size() - 1;
    for(; i >= 0; i--){
        if(s[i] == '5'){
            check = 1;
            i -= 1;
            break;
        }
    }
    if(check){
        for(; i >= 0; i--){
            if(s[i] == '2'){
                kq2 = i;
                break;
            }
        }
    }
    if(kq2 < s.size())
    res = min(res, (int)s.size() - kq2 - 2);

    //50
    int kq3 = INF;
    check = 0;
    i = s.size() - 1;
    for(; i >= 0; i--){
        if(s[i] == '0'){
            check = 1;
            i -= 1;
            break;
        }
    }
    if(check){
        for(; i >= 0; i--){
            if(s[i] == '5'){
                kq3 = i;
                break;
            }
        }
    }
    if(kq3 < s.size())
    res = min(res, (int)s.size() - kq3 - 2);

    //75
    int kq4 = INF;
    check = 0;
    i = s.size() - 1;
    for(; i >= 0; i--){
        if(s[i] == '5'){
            check = 1;
            i -= 1;
            break;
        }
    }
    if(check){
        for(; i >= 0; i--){
            if(s[i] == '7'){
                kq4 = i;
                break;
            }
        }
    }
    if(kq4 < s.size())
    res = min(res, (int)s.size() - kq4 - 2);

    cout << res << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; while(T--)
    solve();
}
