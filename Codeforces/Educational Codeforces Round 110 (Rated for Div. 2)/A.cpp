#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1000005;
int n, ans;
int l[N], r[N];
int a[N];

void inp()
{
   cin >> n;
   for (int i = 1; i <= n; i++) cin >> a[i];
}

void process()
{
    stack <int> s;
    for (int i = 1; i <= n; i++)
    {
        while (!s.empty() && a[i] <= a[s.top()]) s.pop();
        if (s.empty()) l[i] = 1; else l[i] = s.top() + 1;
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = n; i > 0; i--)
    {
        while (!s.empty() && a[i] <= a[s.top()]) s.pop();
        if (s.empty()) r[i] = n; else r[i] = s.top() - 1;
        s.push(i);
    }
    ans = 0;
    for (int i = 1; i <= n; i++)
    	if(r[i] - l[i] + 1 >= a[i]){
    		ans = max(ans, a[i]);
    	}
        
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    inp();
    process();
    return 0;
}