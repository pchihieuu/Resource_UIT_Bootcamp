#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int N = 0;

int n;
int a[60];

void solve(){
	cin >> n;
	if(n % 2 == 0){
		int val = sqrt(n / 2);
		if(val * val == n / 2){
			cout << "YES" << '\n';
			return;
		}
	}
	if(n % 4 == 0){
		int val = sqrt(n / 4);
		if(val * val == n / 4){
			cout << "YES" << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}

}
