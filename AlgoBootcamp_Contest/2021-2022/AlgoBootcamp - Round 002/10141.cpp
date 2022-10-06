#include<bits/stdc++.h>
 
using namespace std;
 
int n, p, r;
float d, best_compliance, best_cost;
string line, name, best_name;
 
int main() {
    for(int T = 1;; T++) {
        scanf("%d %d\n", &n, &p);
        if(n == 0 && p == 0) break;
        if(T > 1) cout << endl;
        for(int i = 0; i < n; i++)
            getline(cin, line);
        best_compliance = 0.0;
        best_cost = 1E37;
        for(int i = 0; i < p; i++) {
            getline(cin, name);
            scanf("%f %d\n", &d, &r);
            for(int i = 0; i < r; i++)
                getline(cin, line);
            if((float) r / p > best_compliance \
                    || (float) r / p == best_compliance && d < best_cost) {
                best_compliance = (float) r / p;
                best_cost = d;
                best_name = name;
            }
        }
        cout << "RFP #" << T << endl;
        cout << best_name << endl;
    }
}