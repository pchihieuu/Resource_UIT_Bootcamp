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
const int N = 1e5 + 5;


void solve(){
	string s;
	cin >> s;
	set<char> Set;
	for(char c: s) Set.insert(c);
	int lock = 0;
	for(char i = 'z'; i >= 'a'; i--){
		if(lock){
			if(s.size() == 0){
				cout << "NO" << '\n';
				return;
			}
			if(s.front() != i && s.back() != i){
				cout << "NO" << '\n';
				return;
			}
			else{
				if(s.front() == i){
					s.erase(0, 1);
				}
				else s.pop_back();
			}
		}
		else{
			if(Set.count(i)){
				lock = 1;
				if(s.front() != i && s.back() != i){
					cout << "NO" << '\n';
					return;
				}
				else{
					if(s.front() == i){
						s.erase(0, 1);
					}
					else s.pop_back();
				}
			}
		}
	}
	if(s.size()){
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';

}


int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}