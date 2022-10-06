#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    string res;
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(c == 'A') res.push_back('T');
        if(c == 'T') res.push_back('A');
        if(c == 'G') res.push_back('C');
        if(c == 'C') res.push_back('G');
    }

    for(int i = res.size() - 1; i >= 0; i--) cout << res[i];

}
