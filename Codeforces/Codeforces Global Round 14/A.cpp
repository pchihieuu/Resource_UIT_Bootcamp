#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
int s;

int val = 0;

void ql(int i, int sum){
	if(sum > s) return;
	int t = (s - sum) / a[i];
	for(int j = 0; j <= t; j++){
		if(i == n){
			if(sum + a[i] * j == s) val += 1;
		}
		else
			ql(i + 1, sum + a[i] * j);
	}
}

int main()
{
    cin >> n;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    cin >> s;
    ql(1, 0);
    cout << val;
}