#include<bits/stdc++.h>
using namespace std;

int f[3005][3005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string a, b;
    cin >> a; a = '#' + a;
    cin >> b; b = '@' + b;
    f[0][0] = 0;
    for(int i = 1; i <= a.size() - 1; i++){
        for(int j = 1; j <= b.size() - 1; j++){
            if(a[i] == b[j]){
                f[i][j] = f[i - 1][j - 1] + 1;
            }
            else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    }

    string res = "";
    int i = a.size() - 1, j = b.size() - 1;
    while(i >= 1 && j >= 1){
        if(a[i] == b[j]){
            res.push_back(a[i]);
            i -= 1;
            j -= 1;
        }
        else{
            if(f[i][j] == f[i - 1][j]){
                i -= 1;
            }
            else{
                j -= 1;
            }
        }
    }

    for(int i = res.size() - 1; i >= 0; i--) cout << res[i];

}
