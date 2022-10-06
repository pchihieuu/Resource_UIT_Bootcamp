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
const int N = 3e4 + 5;

int n;
int a[N];
int l[N], r[N];


void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	stack<II> s;
	for(int i = 1; i <= n; i++){
		while((int)s.size() && s.top().first >= a[i]){
			s.pop();
		}

		if((int)s.size()){
			l[i] = i - s.top().second;
		}
		else{
			l[i] = i;
		}

		s.push(mp(a[i], i));
	}

	while(s.size()) s.pop();
	for(int i = n; i >= 1; i--){
		while((int)s.size() && s.top().first >= a[i]){
			s.pop();
		}

		if((int)s.size()){
			r[i] = s.top().second - i;
		}
		else r[i] = n - i + 1;

		s.push(mp(a[i], i));
	}

	int res = 0;
	int L = 0, R = 0;
	for(int i = 1; i <= n; i++){
		int left = i - l[i] + 1;
		int right = i + r[i] - 1;
		int val = a[i] * (right - left + 1);
		if(val > res){
			res = val;
			L = left;
			R = right;
		}
	}

	cout << res << " " << L << " " << R << '\n';
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}
	
	
}