#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e9 + 5;

const int N = 1e5 + 5;

int n, m;

vector<int> a[105], b[105];
vector<III> s;
vector<int> c[105];

void solve(){

	cin >> n >> m;

	for(int i = 0; i <= m; i++){
		a[i].clear();
		b[i].clear();
		c[i].clear();
	}
	s.clear();

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int x;
			cin >> x;
			a[j].push_back(x);
			b[j].push_back(0);
			s.push_back(mp(x, mp(j, a[j].size() - 1)));
		}
	}
	sort(s.begin(), s.end());

	int val = 1;
	for(int i = 0; i < m; i++){
		int hang = s[i].se.se;
		b[val][hang] = s[i].fi;
		val += 1;
	}
	for(int i = m; i < (int)s.size(); i++){
		int hang = s[i].se.se;
		c[hang].push_back(s[i].fi);
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(b[j][i - 1] != 0) cout << b[j][i - 1];
			else{
				//if(c[i - 1].size() == 0) cout << "DIT COM ME MAY";
				cout << c[i - 1].back();
				c[i - 1].pop_back();
				
			}
			cout << " ";
		}
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	
}
