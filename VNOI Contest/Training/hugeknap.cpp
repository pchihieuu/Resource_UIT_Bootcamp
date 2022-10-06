#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[10005], b[10005], f[1005];
int i, j;

void solve(){
	cin >> n >> m;
	for(i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(i = 1; i <= n; i++){
		cin >> b[i];
	}
	for(i = 1; i <= m; i++){
		f[i] = 0;
	}

}


int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}