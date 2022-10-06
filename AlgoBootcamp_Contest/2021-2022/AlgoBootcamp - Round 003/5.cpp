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

string s[100];
int a[100];
int Test = 0;

int val(char c){
	if(c >= '0' && c <= '9') return c - '0';
	else return 10;
}

void solve(){
	for(int i = 1; i <= 52; i++){
		cin >> s[i];
		a[i] = val(s[i].front());
	}
	int X, Y = 0, pos = 25;
	for(int i = 1; i <= 3; i++){
		X = a[pos--];
		Y += X;
		pos -= 10 - X;
	}
	if(Y > pos){
		Y += (25 - pos);
	}
	cout << "Case " << ++Test << ": " << s[Y] << '\n';
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}
}
