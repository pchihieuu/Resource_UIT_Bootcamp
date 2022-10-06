#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> II;
typedef pair<int, II> III;


const int N = 305;

int n, ans;
vector<III> a[N * N];
int p[N];

int _find(int x)
{
    if (p[x] < 0) return x;
    else return p[x] = _find(p[x]); //huhu
}

int uni(int x, int y)
{
    x = _find(x);
    y = _find(y);
    if (x == y) return 0;
    if (p[x] > p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return 1;
}

void process()
{
    int x, t = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[i].push_back(make_pair(x, make_pair(i, n+1)));
    }

    for (int i = 1; i <= n; i++) p[i] = -1;
    t = n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            if (i == j) continue;
            a[++t].push_back(make_pair(x, make_pair(i, j)));
        }

    sort(a+1, a+1+t);
    for (int i = 1; i <= t; i++)
    
{        //ans += a[i].fi*uni(a[i].se.fi, a[i].se.se);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("test.inp", "r", stdin);
    process();
    return 0;
}