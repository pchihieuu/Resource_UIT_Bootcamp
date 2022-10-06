#include<bits/stdc++.h>
using namespace std;

//#define int long long

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
multiset<int> ms1, ms2;

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	ms1.clear(), ms2.clear();
	ms2.insert(a[1]);

	for(int i = 2; i <= n; i++){
		ms1.insert(a[i]);
		ms2.insert(a[i]);

		while(1){
			auto it = ms1.end(); it--;
			auto it2 = ms2.begin();
			
			int X = *it, Y = *it2;
			if(X > Y){
				ms1.erase(it);
				ms2.erase(it2);
				ms1.insert(Y);
				ms2.insert(X);
			}
			else break;
		}

		for(auto it: ms1){
			cout << it << " ";
		}
		for(auto it: ms2){
			cout << it << " ";
		}
		cout << endl;

		auto it = ms2.begin();
		if(*it != a[i]){
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}



int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}
	
}

/*
1
4
2 1 2 3
*/