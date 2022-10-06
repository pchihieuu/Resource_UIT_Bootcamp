#include<bits/stdc++.h>
using namespace std;

//#define int long long

const int N = 2e5 + 5;

struct query{
    char key;
    int k1, k2, k3;
    query(){
        k1 = 0, k2 = 0, k3 = 0;
    }
};

int n;
int bit[N];
query q[N];


set<int> s;
vector<int> V;
int val(int x){
    int pos = lower_bound(V.begin(), V.end(), x) - V.begin();
    return pos + 1; // BIT starts at 1
}

void update(int x, int val){
    for(; x < N; x += x&-x)  // x <= N  => Runtime Error, because the array starts at 0 and ends at N - 1
        bit[x] += val;
}

int get(int x){
    int val = 0;
    for(; x >= 1; x -= x&-x){
        val += bit[x];
    }
    return val;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n;

    //Roi rac hoa
    for(int i = 1; i <= n; i++){
        cin >> q[i].key;
        if(q[i].key == '+' || q[i].key == '-'){
            cin >> q[i].k1;
            s.insert(q[i].k1);
        }
        else{
            cin >> q[i].k1 >> q[i].k2 >> q[i].k3;
            //Chú ý: q[i].k1 là số thứ tự, không thể nén được
            s.insert(q[i].k2);
            s.insert(q[i].k3);
        }
    }
    for(int i: s) V.push_back(i);

    //Solve
    for(int i = 1; i <= n; i++){
        if(q[i].key == '+'){
            q[i].k1 = val(q[i].k1);
            update(q[i].k1, 1);
        }
        if(q[i].key == '-'){
            q[i].k1 = val(q[i].k1);
            update(q[i].k1, -1);
        }
        if(q[i].key == '?'){
            //q[i].k1 là số thứ tự nên không nén
            q[i].k2 = val(q[i].k2);
            q[i].k3 = val(q[i].k3);
            int l = q[i].k2, r = q[i].k3, res = 0;
            int x = get(l - 1);
            while(l <= r){
                int m = (l + r) / 2;
                int v = get(m);
                if(v - x >= q[i].k1){
                    res = m;
                    r = m - 1;
                }
                else l = m + 1;
            }
             if(res == 0) cout << 0 << '\n';
             else cout << V[res - 1] << '\n';
        }
    }
    
}