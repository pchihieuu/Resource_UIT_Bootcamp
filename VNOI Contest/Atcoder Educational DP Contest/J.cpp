#include<bits/stdc++.h>
using namespace std;

int n;
int a[305];
int f[4];

/**
    Let dp[i][j][k] represent the expected moves for
    i number of plates 1 sushi remaining
    j number of plates 2 sushi remaining
    k number of plates 3 sushi remaining
*/

long double dp[305][305][305];

long double solve(int i, int j, int k){
    if(i < 0 || j < 0 || k < 0) return 0;
    if(i == 0 && j == 0 && k == 0) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    long double val = n + i * solve(i - 1, j, k) + j * solve(i + 1, j - 1, k) + k * solve(i, j + 1, k - 1);
    return dp[i][j][k] = val / (i + j + k);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        f[a[i]] += 1;
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= n; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    cout << setprecision(10) << fixed << solve(f[1], f[2], f[3]);
}
