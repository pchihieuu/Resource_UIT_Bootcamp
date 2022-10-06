#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		int val = __gcd(k, 100);
		cout << 100 / val << '\n';
	}
}