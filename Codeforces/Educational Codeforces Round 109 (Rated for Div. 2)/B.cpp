#include<bits/stdc++.h>
using namespace std;

int n;
int a[100];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	int mi = a[1], ma = a[1];

	int check = 1;
	for(int i = 1; i < n; i++){
		if(a[i] > a[i + 1]) check = 0;
	}
	if(check){
		cout << 0 << '\n';
		return;
	}

	int d = 0;
	for(int i = 1; i <= n; i++){
		mi = min(mi, a[i]);
		ma = max(ma, a[i]);
	}

	if(mi != a[1]) d += 1;
	if(ma != a[n]) d += 1;
	if(mi == a[n] && ma == a[1]) d += 1;

	cout << max(1, d) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}