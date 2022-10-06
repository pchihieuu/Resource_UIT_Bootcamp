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

vector<int> s;
int sz, p;

void write(int r, int c){
	cout << "Line = " << r << ", " << "column = " << c << "." << '\n'; 
}

void solve(){
	int pos = lower_bound(s.begin(), s.end(), p) - s.begin();

	if(pos == 1){
		write(sz / 2 + 1, sz / 2 + 1);
		return;
	}

	int bg = s[pos - 1] + 1;;

	pos = pos * 2 - 1;

	if(bg + pos - 2 >= p){
		int v = bg + pos - 2 - p;
		int l = (sz - pos) / 2 + pos;
		int r = (sz - pos) / 2 + 1 + v;
		write(l, r);
	}
	else if(bg + 2 * pos - 3 >= p){
		int v = p - (bg + pos - 2);
		int r = (sz - pos) / 2 + 1;
		int l = (sz - pos) / 2 + pos - v;
		write(l, r);
	}
	else if(bg + 3 * pos - 4 >= p){
		int v = bg + 3 * pos - 4 - p;
		int l = (sz - pos) / 2 + 1;
		int r = (sz - pos) / 2 + pos - v;
		write(l, r);
	}
	else{
		int v = p - (bg + 3 * pos - 4);
		int r = (sz - pos) / 2 + pos;
		int l = (sz - pos) / 2 + 1 + v;
		write(l, r);
	}
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	s.pb(0);
	s.pb(1);
	for(int i = 3; i <= 2 * N; i += 2){
		int val = s.back();
		val += (i - 2) * 4 + 4;
		s.pb(val);
	}

	while(cin >> sz >> p){
		if(sz == 0) return 0;
		solve();
	}
}