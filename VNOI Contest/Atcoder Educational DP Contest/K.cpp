#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k;
int a[N], dp[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            if(i >= a[j] && !dp[i - a[j]]){
                dp[i] = 1;
            }
        }
    }

    if(dp[k] == 1) cout << "First";
    else cout << "Second";
}
