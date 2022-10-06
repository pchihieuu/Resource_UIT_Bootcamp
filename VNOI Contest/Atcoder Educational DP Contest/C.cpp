#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N][5], f[N][5];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 3; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= 3; i++){
        f[1][i] = a[1][i];
    }

    int res = max(a[1][1], max(a[1][2], a[1][3]));
    for(int i = 2; i <= n; i++){
        for(int j1 = 1; j1 <= 3; j1++){
            for(int j2 = 1; j2 <= 3; j2++){
                if(j1 == j2) continue;
                f[i][j1] = max(f[i][j1], f[i - 1][j2] + a[i][j1]);
            }
            res = max(res, f[i][j1]);
        }
    }

    cout << res;


}
