#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	int a[5];
	cin >> t;
	for(int test = 1; test <= t; test++){
		for(int i = 1; i <= 3; i++){
			cin >> a[i];
		}
		sort(a + 1, a + 3 + 1);
		cout << "Case " << test << ": " << a[2] << '\n';
	}
	
}