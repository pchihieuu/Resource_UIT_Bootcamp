#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int k, m, n, x, y;
	while(1){
		cin >> k;
		if(!k) break;
		cin >> m >> n;
		for(int i = 1; i <= k; i++){
			cin >> x >> y;
			x -= m;
			y -= n;

			if(x == 0 || y == 0){
				cout << "divisa";
			}
			else if(x > 0 && y > 0){
				cout << "NE";
			}
			else if(x < 0 && y > 0){
				cout << "NO";
			}
			else if(x < 0 && y < 0){
				cout << "SO";
			}
			else cout << "SE";
			cout << '\n';
		}
	}
}