#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const int base = 27;

vector<vector<char> > a;
vector<vector<int> > hn, hd;
int n, m, q;

int p[N];

map<int, int> ma[10 + 5];
int d[N];
int par[N];


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> q;
	a = vector<vector<char> > (n + 5, vector<char> (m + 5, 'a'));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}

	p[0] = 1;
	for(int i = 1; i <= 10; i++){
		p[i] = (p[i - 1] * base);
	}

	for(int i = 1; i <= q; i++){
		par[i] = i;
	}

	for(int i = 1; i <= q; i++){
		string x;
		cin >> x;
		int l = x.size();
		int tam = 0;
		for(int j = 0; j < l; j++){
			tam = (tam * p[1] + x[j] - 'a');
		}
		if(ma[l].count(tam)){
			par[i] = ma[l][tam];
		}
		else{
			ma[l][tam] = i;
		}
		
	}

	hn = vector<vector<int> > (n + 5, vector<int> (m + 5, 0));
	hd = hn;
	//ngang
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			hn[i][j] = (hn[i][j - 1] * p[1] + a[i][j] - 'a');
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int k = 2; k <= 10; k++){
				if(j + k - 1 > m) break;
				int val = (hn[i][j + k - 1] - hn[i][j - 1] * p[k]);
				if(ma[k].count(val)){
					d[(int)(ma[k][val])] = 1;
				}
			}
		}
	}



	//doc
	for(int j = 1; j <= m; j++){
		for(int i = 1; i <= n; i++){
			hd[i][j] = (hd[i - 1][j] * p[1] + a[i][j] - 'a');
		}
	}

	for(int j = 1; j <= m; j++){
		for(int i = 1; i <= n; i++){
			for(int k = 2; k <= 10; k++){
				if(i + k - 1 > n) break;
				int val = (hd[i + k - 1][j] - hd[i - 1][j] * p[k]);
				if(ma[k].count(val)){
					d[(int)(ma[k][val])] = 1;
				}
			}
		}
	}

	for(int i = 1; i <= q; i++){
		d[i] = d[par[i]];
	}

	for(int i = 1; i <= q; i++){
		cout << d[i];
	}

}
/*
2 2 4
da
oc

co
da
ac
dc
*/