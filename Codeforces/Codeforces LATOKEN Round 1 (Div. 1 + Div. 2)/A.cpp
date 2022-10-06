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

void solve(){
	int n; cin >> n;
	vector<int> a(n, 0);
	for(int &i: a) cin >> i;
	sort(a.begin(), a.end());
	int L = 0, R = 0;
	int val = INF;
	for(int i = 1; i < (int)a.size(); i++){
		if(a[i] - a[i - 1] < val){
			val = a[i] - a[i - 1];
			R = i;
			L = i - 1;
		}
	}

	int l = a[L], r = a[R];
	a[L] = 0, a[R] = 0;
	cout << l << " ";
	for(int i: a){
		if(i > 0){
			cout << i << " ";
		}
	}
	cout << r << '\n';
	
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}