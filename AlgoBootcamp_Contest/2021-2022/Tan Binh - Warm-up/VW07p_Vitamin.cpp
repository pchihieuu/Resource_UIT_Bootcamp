#include<bits/stdc++.h>
using namespace std;

int n, x;
int a[105];
int mark[1000005];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> x;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i - 1];
	}
	
	for(int i = 0; i <= x; i++){
		mark[i] = 1e9;
	}
	mark[x] = 0;

	int val = a[n] - a[n - 1];

	for(int i = n; i >= 1; i--){
		for(int j = x; j >= 0; j--){
			if(mark[j] == 1e9 || j - a[i] < 0) continue;
			mark[j - a[i]] = min(mark[j - a[i]], mark[j] + i + 1);
		}
	}

	for(int j = x; j >= 0; j--){
		if(mark[j] == 1e9) continue;
		if(j - a[n] >= 0 && (j - a[n]) % val == 0){
			mark[0] = min(mark[0], mark[j] + n + 1 + (j - a[n]) / val);
		}	
	}

	if(mark[0] == 1e9) cout << -1;
	else cout << mark[0] - 1;
}