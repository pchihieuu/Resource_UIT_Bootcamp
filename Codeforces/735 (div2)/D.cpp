#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 4e5 + 5;

int n;
vector<char> ans;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while(T--){
        cin >> n;
        int x = n / 2;
        ans.clear();
        for(int i = 1; i <= x - 1; i++){
            ans.pb('a');
        }
        ans.pb('b');
        for(int i = 1; i <= x; i++){
            ans.pb('a');
        }
        for(int i = 2; i <= 25; i++){
            if((int)ans.size() == n) break;
            ans.pb(char(i + 'a'));
        }
        for(char c: ans) cout << c;
        cout << '\n';
    }
}