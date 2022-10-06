#include<bits/stdc++.h>
using namespace std;

#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n;
int a[N];

void solve(){
	int sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
	if(sum % n != 0){
		cout << -1 << '\n';
		return;
	}
	int res = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] > (sum / n)) res += 1;
	}
	cout << res << '\n';
}


int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}