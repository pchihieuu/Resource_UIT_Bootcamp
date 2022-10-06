#include<bits/stdc++.h>
using namespace std;

int n, m;

void solve(){
	cin >> n >> m;
	vector<char> a(n + 5, '0'), c(n + 5, '0');
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	vector<char> b(n + 5, '0');
	while(m--){
		int check = 1;
		for(int i = 1; i <= n; i++){
			if(b[i] != a[i]){
				check = 0;
			}
		}
		if(check == 1) break;
		for(int i = 1; i <= n; i++){
			b[i] = a[i];

		}

		for(int i = 1; i <= n; i++){
			if(a[i] == '0' && (int)(a[i - 1] - '0') + (int)(a[i + 1] - '0') == 1) b[i] = '1';
		}
		for(int i = 1; i <= n; i++){
			swap(a[i], b[i]);
		}
	}

	for(int i = 1; i <= n; i++){
		cout << a[i];
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	
}