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
const int N = 262143 + 5;

int k;
int n;
char s[N];
int it[4 * N];
II f[4 * N];
int c[4 * N];
int d[4 * N];

void merge(int id){
	if(s[d[id]] == '?'){
		it[id] = it[id * 2] + it[id * 2 + 1];
	}
	if(s[d[id]] == '0'){
		it[id] = it[id * 2];
	}
	if(s[d[id]] == '1'){
		it[id] = it[id * 2 + 1];
	}
}

void build(int id){
	if(id >= (1 << (k - 1))){
		it[id] = 1;
		if(s[d[id]] == '?')
			it[id]  = 2;
		return;
	}
	build(id * 2);
	build(id * 2 + 1);
	merge(id);
}

void U(int id){
	if(s[d[id]] == '?'){
		if(id >= (1 << (k - 1))){
			it[id] = 2;
		}
		else it[id] = it[id * 2] + it[id * 2 + 1];
	}

	if(s[d[id]] == '1'){
		if(id >= (1 << (k - 1))){
			it[id] = 1;
		}
		else it[id] = it[id * 2 + 1];
	}

	if(s[d[id]] == '0'){
		if(id >= (1 << (k - 1))){
			it[id] = 1;
		}
		else it[id] = it[id * 2];
	}
}

void update(int id){
	if(id == 0) return;
	merge(id);
	update(id / 2);
	
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int T; cin >> T; while(T--){solve();}
	cin >> k;
	for(int i = 1; i < (1 << k); i++){
		cin >> s[i];
	}

	int D = 0;
	for(int i = k - 1; i >= 0; i--){
		for(int t = (1 << i); t <= (1 << i) + (1 << i) - 1; t++){
			c[++D] = t;
			d[t] = D;
		}
	}

	build(1);

	int q;
	cin >> q;
	for(int i = 1; i <= q; i++){
		int pos;
		char x;
		cin >> pos >> x;
		s[pos] = x;
		U(c[pos]);
		update(c[pos] / 2);
		cout << it[1] << '\n';
	}
}
/*
3
0110?11
1
5 1
*/