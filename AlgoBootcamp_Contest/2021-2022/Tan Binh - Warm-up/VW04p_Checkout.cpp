#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long

int main()
{
    ld d, a1, a2, v, t ;

    cin >> d >> a1 >> a2 >> v >> t ;

    ld a = (ld)1 / (a1 * 2) + (ld)1 / (a2 * 2) ;
    ld x = (-t + sqrt(t * t + 4 * a * d)) / (a * 2) ;
    ld res = 0;
    if (x <= v) {
        res = x / a1 + x / a2 + t ;
    }
    else {
        res = v / a1 + v / a2 + (d / v - v / (a1 * 2) - v / (a2 * 2)) ;
    }

    res += 5e-14;

    cout << setprecision(12) << fixed << res;
}