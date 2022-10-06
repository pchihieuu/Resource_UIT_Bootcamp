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

int a[N];

void solve(){
	int n;
	cin >> n;
	set<int> s;
	s.clear();
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s.insert(a[i]);
	}

	int KT = 0;
	while(1){
		int check = 1;
		for(int i = 1; i <= n; i++){
			if(check == 0) break;
			for(int j = i + 1; j <= n; j++){
				if(!s.count(abs(a[i] - a[j]))){
					n += 1;
					a[n] = abs(a[i] - a[j]);
					s.insert(a[n]);
					check = 0;
					break;
				}
			}
		}
		
		if(check == 1){
			KT = 1;
			break;
		}
		if(n >= 300) break;
	}

	if(KT == 1){
		cout << "Yes" << '\n';
		cout << n << '\n';
		for(int i = 1; i <= n; i++){
			cout << a[i] << " ";
		}
		cout << '\n';
	}
	else cout << "NO" << '\n';

}



int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}
