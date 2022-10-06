#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
const int N = 121;
using namespace std;
char ch[N];
int n;
vi f[N][N];
void fix(vi &a)
{
    a.push_back(0);
    for (int i = 0; i < (int)a.size()-1; i++)
    {
        a[i+1] += a[i]/10;
        a[i] %= 10;
        if (a[i] < 0)
        {
            a[i] += 10;
            a[i+1] -= 1;
        }
    }
    while (a.size() > 1 && a.back() == 0) a.pop_back();
}
vi operator+(vi a, vi b)
{
    while (a.size() < b.size()) a.push_back(0);
    while (b.size() < a.size()) b.push_back(0);
    for (int i = 0; i < (int)b.size(); i++)
        a[i] = a[i]+b[i];
    fix(a);
    return (a);
}
vi operator-(vi a, vi b)
{
    while (a.size() < b.size()) a.push_back(0);
    while (b.size() < a.size()) b.push_back(0);
    for (int i = 0; i < (int)b.size(); i++)
        a[i] = a[i]-b[i];
    fix(a);
    return a;
}
void inp()
{
    string s;
    cin >> s;
    n = 0;
    for(int i = 0; i < (int)s.size(); i++){
    	n += 1;
    	ch[n] = s[i];
    }
}
void write(vi a)
{
    for (int i = a.size()-1; i >= 0; i--) cout << a[i];
}
void process()
{
    vi t;
    t.push_back(1);
    for (int i = 1; i <= n; i++) f[i][i].push_back(1);
    for (int i = n; i > 0; i--)
        for (int j = i; j <= n; j++)
        {
            if (ch[i] == ch[j]) f[i][j] = f[i][j-1]+f[i+1][j]+t;
            else f[i][j] = f[i+1][j]+f[i][j-1]-f[i+1][j-1];
        }
    write(f[1][n]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("test.inp","r", stdin);
    inp();
    process();
    return 0;
}