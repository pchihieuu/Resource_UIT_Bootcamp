#include<bits/stdc++.h>
using namespace std;

int n;
int a[100005];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	int d = 0;
	int check = 0;
	int val = 2e9;
	for(int i = 1; i <= n; i++){
		if(i > 1){
			if(a[i] == a[i - 1])
				check = 1;
			val = min(val, abs(a[i] - a[i - 1]));
		}
		if(a[i] <= 0){
			d += 1;
		}
		else{
			if(a[i] > val) check = 1;
			d += 1 - check;
			break;
		}
	}

	cout << d << '\n';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	
}