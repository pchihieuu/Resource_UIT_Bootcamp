#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1005;
const int M = 1e9 + 7;

int H, W;
char a[N][N];
int f[N][N];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> H >> W;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> a[i][j];
        }
    }

    f[1][1] = 1;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(a[i][j] == '#') continue;
            if(i > 1 && a[i - 1][j] == '.'){
                f[i][j] = f[i - 1][j];
            }
            if(j > 1 && a[i][j - 1] == '.'){
                f[i][j] += f[i][j - 1];
            }
            f[i][j] %= M;
        }
    }

    cout << f[H][W];

}
