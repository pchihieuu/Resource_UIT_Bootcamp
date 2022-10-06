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
const int N = 4e5 + 5;


void solve(){
	int h, w;
	cin >> h >> w;

	if(h <= 4 && w <= 4){
		cout << 1;
		for(int i = 2; i < w; i++) cout << 0;
		cout << 1;
		cout << '\n';
		for(int i = 2; i < h; i++){
			for(int j = 1; j <= w; j++) cout << 0;
			cout << '\n';
		}
		cout << 1;
		for(int i = 2; i < w; i++) cout << 0;
		cout << 1;
		cout << '\n';
		return;
	}

	if(w & 1){
		for(int i = 1; i <= w; i++){
			if(i & 1) cout << 1;
			else cout << 0;
		}
		cout << '\n';

		for(int i = 2; i <= h - 2; i++){
			if(i & 1){
				cout << 1;
				for(int j = 2; j < w; j++){
					cout << 0;
				}
				cout << 1;
				cout << '\n';
			}
			else{
				for(int j = 1; j <= w; j++){
					cout << 0;
				}
				cout << '\n';
			}
		}

		for(int i = 1; i <= w; i++) cout << 0;
		cout << '\n';
		for(int i = 1; i <= w; i++){
			if(i & 1) cout << 1;
			else cout << 0;
		}
		cout << '\n';
	}
	else{
		for(int i = 1; i <= w; i++){
			if(i & 1) cout << 1;
			else cout << 0;
		}
		cout << '\n';

		for(int i = 2; i <= h - 2; i++){
			if(i & 1){
				cout << 1;
				for(int j = 2; j < w; j++){
					cout << 0;
				}
				cout << 1;
				cout << '\n';
			}
			else{
				for(int j = 1; j <= w; j++){
					cout << 0;
				}
				cout << '\n';
			}
		}

		for(int i = 1; i <= w; i++) cout << 0;
		cout << '\n';
		for(int i = 1; i <= w; i++){
			if(i & 1) cout << 0;
			else cout << 1;
		}
		cout << '\n';
	}


}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}