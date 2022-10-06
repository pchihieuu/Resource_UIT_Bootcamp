#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, a, b;
int x[105];


void solve()
{
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++)
	{
		char c; 
		cin >> c;
		x[i] = c - '0';
	}
	
	int ans = n * a;

	if(b >= 0)
	{
		ans += n * b;
		cout << ans << '\n';
		return;
	}

	int cnt0 = 0, cnt1 = 0;
	int key = -1;
	for(int i = 1; i <= n; i++)
	{
		if(x[i] != key)
		{
			key = x[i];
			if(x[i] == 1) cnt1 += 1;
			else cnt0 += 1;
		}
	}

	int cnt = min(cnt0, cnt1) + 1;

	ans += cnt * b;

	cout << ans << '\n';
}

int32_t main(){
	
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	int T; cin >> T; 
	while(T--)
	{
		solve();
	}	
}