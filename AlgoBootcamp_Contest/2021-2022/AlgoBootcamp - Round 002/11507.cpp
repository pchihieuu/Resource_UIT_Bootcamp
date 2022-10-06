#include<bits/stdc++.h>
using namespace std ;
int main()
{   
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s ;
    int L ;
    while(1) {
        cin >> L ;
        if (L == 0) break ;
        int dir = 1;
        char c = 'x' ;
        for (int i = 1; i < L ; i++) {
            cin >> s ;
            if(s[0] == 'N') continue ;
            int temp ;
            if(s[0] == '+') temp = 1;
            else temp = -1;
            if (c =='x') {
                dir = dir* temp;
                c = s[1] ;
            }
            else if (c == 'y' && s[1] == 'y') {
                dir = - dir* temp;
                c = 'x' ;
            }
            else if (c == 'z' && s[1] == 'z') {
                dir = - dir* temp;
                c = 'x' ;
            }
        }
        if (dir == 1) cout << '+' << c << '\n' ;
        else cout << '-' << c << '\n' ;
    }
}