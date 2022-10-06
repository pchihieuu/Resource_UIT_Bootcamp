#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int res = 1e18;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            int val = a;
            if(i == 1){
                val = a + b;
            }
            if(i == 2){
                val = a - b;
            }
            if(i == 3){
                val = a * b;
            }
            if(j == 1){
                val = val + c;
            }
            if(j == 2){
                val = val - c;
            }
            if(j == 3){
                if(i == 1){
                    val = a + b * c;
                }
                if(i == 2){
                    val = a - b * c;
                }
                if(i == 3){
                    val = a * b * c;
                }
            }
            res = min(res, abs(val));
        }
    }
    cout << res << '\n';

}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
