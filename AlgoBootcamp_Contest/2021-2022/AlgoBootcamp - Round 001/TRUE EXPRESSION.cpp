#include<bits/stdc++.h>
using namespace std;

int n, s;
int a[105];
int d[105];

int main()
{
	cin >> n >> s;
	int sum = (n + 1) * n / 2;
	if(s > sum)
	{
		cout << "NO_SOLUTION";
		return 0;
	}

	sum = sum - s;
	if(sum % 2 == 1)
	{
		cout << "NO_SOLUTION";
		return 0;
	}

	sum = sum / 2;

	for(int i = 1; i <= n; i++){
		d[i] = 1;
	}

	for(int i = n; i >= 1; i--)
	{
		if(sum >= i)
		{
			sum -= i;
			d[i] = 0;
		}
	}

	for(int i = 1; i <= n; i++)
	{
		if(d[i]) cout << '+';
		else cout << '-';
	}
}