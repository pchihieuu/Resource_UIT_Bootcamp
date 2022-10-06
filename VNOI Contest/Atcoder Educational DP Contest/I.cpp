#include<bits/stdc++.h>
using namespace std;

const int N = 3005;
int n;
double a[N], p[N][N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    p[1][0] = 1 - a[1];
    p[1][1] = a[1];
    for(int i = 2; i <= n; i++){
        p[i][0] = p[i - 1][0] * (1 - a[i]);
        for(int j = 1; j <= i; j++){
            // Chose
            p[i][j] += p[i - 1][j - 1] * a[i];

            // Not chose
            p[i][j] += p[i - 1][j] * (1 - a[i]);
        }
    }

    double res = 0;
    for(int i = n / 2 + 1; i <= n; i++){
        res += p[n][i];
    }

    cout << setprecision(10) << fixed << res;
}
