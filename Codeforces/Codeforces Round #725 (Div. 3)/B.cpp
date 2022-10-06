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

int n;
int a[N];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	int ma = a[1], mi = a[1];
	for(int i = 1; i <= n; i++){
		ma = max(ma, a[i]);
		mi = min(mi, a[i]);
	}
	int res = 0;

	int check = 0;
	int l = 1, r = n;
	for(int i = 1, j = n; i <= n; i++, j--){
		if(a[i] == ma || a[i] == mi){
			l = i + 1;
			res = i;
			break;
		}
		if(a[j] == ma || a[j] == mi){
			r = j - 1;
			res = n - j + 1;
			check = 1;
			break;
		}
	}

	if(check){
		for(int i = 1, j = r; i <= r; i++, j--){
			if(a[i] == ma || a[i] == mi){
				res += i;
				break;
			}
			if(a[j] == ma || a[j] == mi){
				res += r - j + 1;
				check = 1;
				break;
			}
		}
	}
	else{
		for(int i = l, j = n; i <= n; i++, j--){
			if(a[i] == ma || a[i] == mi){
				res += i - l + 1;
				break;
			}
			if(a[j] == ma || a[j] == mi){
				res += n - j + 1;
				check = 1;
				break;
			}
		}
	}

	cout << res << '\n';
}


int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}