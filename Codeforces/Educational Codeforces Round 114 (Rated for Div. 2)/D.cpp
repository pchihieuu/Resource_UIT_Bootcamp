#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m;
vector<int> a[N];
set<vector<int> > key;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int c;
        cin >> c;
        for(int j = 1; j <= c; j++){
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        vector<int> x;
        for(int j = 1; j <= n; j++){
            int _x;
            cin >> _x;
            x.push_back(_x);
        }
        key.insert(x);
    }

    vector<int> temp;

    for(int i = 1; i <= n; i++){
        temp.push_back(a[i].size());
    }
    if(!key.count(temp)){
        for(int i: temp) cout << i << " ";
        return 0;
    }

    for(int i = 1; i <= m; i++){
        temp.clear();

        for(int j = 1; j <= n; j++){

        }
    }
}
