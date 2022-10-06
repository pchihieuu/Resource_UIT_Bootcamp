#include <bits/stdc++.h>
using namespace std;

int main()
{
	while( true ){
        double H, U, D, F;
        cin >> H;
        if( H <= 0 )
            break;
        cin >> U >> D >> F;
        F = (U * F)/100.0;
        
        int day = 1;
        double cur = 0.0;
        while( true ){
            cur += U;
            if( cur > H ){
                cout << "success on day " << day << endl;
                break;
            }
            U = max(U - F, 0.0);
            cur -= D;
            if( cur < 0.0 ){
                cout << "failure on day " << day << endl;
                break;
            }
            day++;
        }
    }
}
