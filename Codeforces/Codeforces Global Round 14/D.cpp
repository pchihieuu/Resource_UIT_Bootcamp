#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int N = 2e5;

multiset<int> L, R;


int n, l, r;
vector<int> xoa, s;

void solve(){
	xoa.clear();
	s.clear();
	L.clear();
	R.clear();

	cin >> n >> l >> r;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(i <= l){
			L.insert(x);
		}
		else  R.insert(x);
	}

	for(auto i: L){
		auto it = R.find(i);
		if(it != R.end()){
			R.erase(it);
			xoa.push_back(i);
		}
	}

	for(int i = 0; i < (int)xoa.size(); i++){
		L.erase(L.find(xoa[i]));
	}

	if((int)R.size() > (int)L.size()) swap(L, R);

	int res = 0;
	int cl = (int)L.size() - (int)R.size();
	for(auto i: L){
		s.push_back(i);
		if(s.size() >= 2 && cl > 0 && s.back() == s[(int)s.size() - 2]){
			s.pop_back();
			s.pop_back();
			cl -= 2;
			res += 1;
		}
	}
	
	
	res += (int)s.size();
	

	cout << res << '\n';
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}

}
