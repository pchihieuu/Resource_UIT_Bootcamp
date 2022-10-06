#include<bits/stdc++.h>
using namespace std;

//#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ld long double

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const double EPS = 1e-9;

double cal(double c, double m, double p, double v){
	double res = p;
	
	if(c > EPS){
		if(c > v){
			if(m > EPS){
				res += c + c * cal(c - v, m + v / 2, p + v / 2, v);
			}
			else{
				res += c + c * cal(c - v, 0, p + v, v);
			}
		}
		else{
			if(m > EPS){
				res += c + c * cal(0, m + c / 2, p + c / 2, v);
			}
			else{
				res += c + c * cal(0, 0, 1, v);
			}
		}
	}

	if(m > EPS){
		if(m > v){
			if(c > EPS){
				res += m + m * cal(c + v / 2, m - v, p + v / 2, v);
			}
			else{
				res += m + m * cal(0, m - v, p + v, v);
			}
		}
		else{
			if(c > EPS){
				res += m + m * cal(c + m / 2, 0, p + m / 2, v);
			}
			else{
				res += m + m * cal(0, 0, 1, v);
			}
		}
	}
	return res;
}

void solve(){
	double c, m, p, v;
	cin >> c >> m >> p >> v;

	double res = cal(c, m, p, v);
	cout << setprecision(12) << fixed << res << '\n';
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}
}