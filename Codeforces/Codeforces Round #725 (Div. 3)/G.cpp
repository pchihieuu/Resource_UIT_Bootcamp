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
const int N = 1e5 + 5;

int n, x, y, a, b;

int bs1(){
	int l = 1, r = 1e9;
	int ans = 0;
	while(l <= r){
		int m = (l + r) / 2;
		if(y - m * b < 0 || x - m * a < 0){
			r = m - 1;
			continue;
		}
		if(x - m * a <= y - m * b){
			ans = m;
			r = m - 1;
		}
		else{
			ans = m;
			l = m + 1;
		}
	}
	return ans;
}

int bs2(){
	int l = 1, r = 1e9;
	int ans = 0;
	while(l <= r){
		int m = (l + r) / 2;
		if(x - m * a - m * b < 0 ||  y - m * b - m * a < 0){
			r = m - 1;
		}
		else{
			ans = m;
			l = m + 1;
		}
	}
	return ans;
}

void solve(){
	cin >> x >> y >> a >> b;
	if(x < y) swap(x, y);
	if(a < b) swap(a, b);

	//cout << x << " " << y << " " << a << " " << b << endl;

	int res = bs1();
	x = x - res * a;
	y = y - res * b;
	if(x < y) swap(x, y);

	//cout << res << endl;

	int val = bs2();
	res += val * 2;

	//cout << val << endl;

	x = x - val * a - val * b;
	y = y - val * a - val * b;

	while(x >= a && y >= b){
		res += 1;
		x -= a;
		y -= b;
		if(x < y) swap(x, y);
	}

	cout << res << '\n';
}


int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}	
}

/*
1
52 311 13 27
*/