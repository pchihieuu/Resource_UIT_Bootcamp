#include <bits/stdc++.h>
#define pii pair <int, int>
#define fi first
#define se second
const int mod = 65536;

using namespace std;

const int N = 250005;
long long ans;
int seed, mul, add, n, k;
int a[N];
void inp()
{
   cin >> seed >> mul >> add >> n >> k;
}
auto ed(auto t)
{
    t--;
    return t;
}
void process()
{
    multiset <pii> s1, s2;
    ans = 0;
    a[1] = seed;
    for (int i = 2; i <= n; i++) a[i] = ((a[i-1]*mul)%mod+add)%mod;
    for (int i = 1; i < k; i++) s1.insert({a[i], i});
    for (int i = k; i <= n; i++)
    {
        if (s1.size() && ed(s1.end())->fi >= a[i]) s1.insert({a[i], i});
        else s2.insert({a[i], i});
        while (s1.size() && s2.size() && s1.size() > s2.size() && s1.size()-1 != s2.size())
        {
            s2.insert({ed(s1.end())->fi, ed(s1.end())->se});
            s1.erase(ed(s1.end()));
        }
        while (s1.size() && s2.size() && s1.size() < s2.size())
        {
            s1.insert(*(s2.begin()));
            s2.erase(s2.begin());
        }
  
        ans += ed(s1.end())->fi;
        if (s1.find({a[i-k+1], i-k+1}) != s1.end())
            s1.erase(s1.find({a[i-k+1], i-k+1}));
        else s2.erase(s2.find({a[i-k+1], i-k+1}));
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    int p;
    cin >> p;
    for (int test = 1; test <= p; test++)
    {
        inp();
        process();
        cout << "Case #" << test <<": " << ans << '\n';
    }
    return 0;
}