#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int N = 1e6;

int a[N], d[N];
int n;

int check(){
	for(int i = 1; i <= n; i++){
		d[i] = 0;
	}
	for(int i = 1; i <= n; i++){
		d[a[i]] = 1;
		for(int j = 2; j < n; j++){
			if(d[j] == 0 && d[j - 1] && d[j + 1]) return 0;
		}
	}
	return 1;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		a[i] = i;
	}

	int res = 0;
	do{
		if(check()) res += 1;
	}
	while(next_permutation(a + 1, a + n + 1));
	cout << res << endl;

}
