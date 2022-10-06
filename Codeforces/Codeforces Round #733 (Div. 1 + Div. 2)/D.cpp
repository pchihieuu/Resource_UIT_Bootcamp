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
int a[N], b[N];

void solve(){
	set<int> s, s1;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s.insert(a[i]);
	}

	for(int i = 1; i <= n; i++){
		if(s.count(i) == 0) s1.insert(i);
	}

	cout << s.size() << '\n';
	for(int i = 1; i <= n; i++){
		if(s.count(a[i])){
			b[i] = a[i];
			s.erase(a[i]);
		}
		else{
			int val = *s1.rbegin();
			int val1 = *s1.begin();
			if(val != i){
				b[i] = val;
				s1.erase(val);
			} 
			else{
				b[i] = val1;
				s1.erase(val1);
			} 
			
		}
	}

	int check = 1;

	for(int i = 1; i <= n; i++){
		if(b[i] == i) check = 0;
	}

	if(check == 0){
		s.clear();
		s1.clear();
		for(int i=  1; i <= n; i++){
			s.insert(a[i]);
		}
		for(int i = 1; i <= n; i++){
			if(s.count(i) == 0) s1.insert(i);
		}
		for(int i = n; i >= 1; i--){
			if(s.count(a[i])){
				b[i] = a[i];
				s.erase(a[i]);
			}
			else{
				int val = *s1.begin();
				int val1 = *s1.rbegin();
				if(val != i){
					b[i] = val;
					s1.erase(val);
				} 
				else{
					b[i] = val1;
					s1.erase(val1);
				} 
				
			}
		}
	}
	
	for(int i = 1; i <= n; i++) cout << b[i] << " ";
	cout << '\n';


}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}