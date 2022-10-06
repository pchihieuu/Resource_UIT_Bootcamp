#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		int a, b;
		cin >> a >> b;
		if(a < b){
			cout << '<';
		}
		else if(a > b){
			cout << '>';
		}
		else cout << '=';
		cout << '\n';
	}

}