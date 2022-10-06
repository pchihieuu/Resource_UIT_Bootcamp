#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
typedef pair<int, int> II;

const int MOD = 998244353;

const int N = 2e6 + 5;

int n;

int f[N];
int x[N];
II d[N];
set<vector<II> > S;


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;

	for(int i = 1; i <= n; i++){
		x[i * 2 - 1] = i;
		x[i * 2] = i;
	}

	n *= 2;

	for(int i = 1; i <= n / 2; i++){
		d[i] = mp(0, 0);
	}

	
	do{
		for(int i = 1; i <= n; i++){
			if(d[x[i]].first == 0){
				d[x[i]].first = i;
			}
			else d[x[i]].second = i;
		}

		int k = 1;
		for(int i = 1; i <= n / 2; i++){
			for(int j = i + 1; j <= n / 2; j++){
				if(d[i].second - d[i].first == d[j].second - d[j].first) continue;
				if(d[i].first <= d[j].first && d[j].second <= d[i].second) continue;
				if(d[j].first <= d[i].first && d[i].second <= d[j].second) continue;
				k = 0;
				break;
			}
		}

		sort(d + 1, d + n/2 + 1);
		if(k == 1){
			vector<II> a;
			a.clear();
			for(int i = 1; i <= n / 2; i++){
				//cout << d[i].first << " " << d[i].second << endl;
				a.push_back(mp(d[i].first, d[i].second));
			}
			//cout << endl;
			S.insert(a);
			
		}

		for(int i = 1; i <= n / 2; i++){
			d[i] = mp(0, 0);
		}
	}
	while(next_permutation(x + 1, x + n + 1));

	cout << (int)S.size();	
}