

#include<bits/stdc++.h>
using namespace std;

int n;
int a[105];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int d = 1;
	for(int i = 2; i <= n; i++){
		if(a[i] == a[1]){
			d += 1;
		}
		else break;
	}
	cout << n - d << endl;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve(); 
	}
	
}