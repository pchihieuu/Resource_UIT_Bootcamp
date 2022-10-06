#include<bits/stdc++.h>
using namespace std;

//#define int long long

void solve()
{
	int s;
	cin >> s;
	int val = 0, cnt = 0;
	for(int i = 1; i <= 5000; i += 2)
	{
		val += i;
		cnt += 1;
		if(val >= s) break;
	}
	cout << cnt << '\n';
}

int32_t main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	int T; cin >> T; 
	while(T--)
	{
		solve();
	}
}