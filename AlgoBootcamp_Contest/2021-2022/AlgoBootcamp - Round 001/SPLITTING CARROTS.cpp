#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];
int f[N];

bool check(){

	int sum = 0;
	for(int i = 1; i <= n; i++){
		sum += a[i];
	}

	if(sum % 2 == 1) return 0;

	f[0] = 1;
	for(int i = 1; i <= sum / 2; i++){
		f[i] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = sum / 2; j >= 1; j--){
			if(j >= a[i] && f[j - a[i]]) f[j] = 1;
		}
	}
	return f[sum / 2];


}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	int sum = 0;
	for(int i = 1; i <= n; i++){
		sum += a[i];
	}

	if(sum % 2 == 1){
		cout << 0;
		return 0;
	}

	if(check() == 0){
		cout << 0;
		return 0;
	}


	for(int i = n; i >= 1; i--){
		int tam = a[i];
		a[i] = 0;
		int val = check();

		if(val == 0){
			cout << 1 << '\n';
			cout << i;
			return 0;
		}
		a[i] = tam;
	}
}

