#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Graham{
    int n;
    int pos = 0;
    vector<pair<int, int> > a;
    pair<int, int> origin;

    Graham(){}
    Graham(int n): n(n), a(n + 5){}

    void addPoint(int u, int v){
        pos += 1;
        a[pos] = make_pair(u, v);
    }

    bool ccw(pair<int, int> O, pair<int, int> A, pair<int, int> B) {
        A.first -= O.first, A.second -= O.second;
        B.first -= O.first, B.second -= O.second;
        return A.first * B.second > A.second * B.first;
    }

    long double d(pair<int, int> A, pair<int, int> B){
        long double x = (long double)(A.first - B.first) * (A.first - B.first)
                        + (long double)(A.second - B.second) * (A.second - B.second);
        return sqrt(x);
    }

    void process(){
        sort(a.begin() + 1, a.begin() + n + 1);
        origin = a[1];
        sort(a.begin() + 2, a.begin() + n + 1, [&](pair<int, int> A, pair<int, int> B){
             return ccw(origin, A, B);
            });
        a[0] = a[n];
        a[n + 1] = a[1];
        int j = 1;
        for (int i = 1; i <= n + 1; i++) {
            while (j > 2 && !ccw(a[j - 2], a[j - 1], a[i])) j--;
            a[j++] = a[i];
        }
        n = j - 2;

        long double perimeter = 0;
        for (int i = 1; i < n; i++){
            perimeter += d(a[i], a[i + 1]);
        }
        perimeter += d(a[n], a[1]);
        cout << setprecision(10) << fixed << perimeter;
    }
};

int n, d;

int32_t main() {
    cin >> n >> d;
    Graham g(4 * n);
    for (int i = 1; i <= n; i++){
        int u, v;
        cin >> u >> v;
        g.addPoint(u + d, v);
        g.addPoint(u - d, v);
        g.addPoint(u, v + d);
        g.addPoint(u, v - d);
    }
    g.process();
}
/*
4 100000000
-100000000 -100000000
100000000 -100000000
-100000000 100000000
100000000 100000000
*/
