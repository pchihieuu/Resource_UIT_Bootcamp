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
const int N = 1e5 + 5;

int a, b, k;

vector<II> v1, v2;

vector<int> nt;
int mark[N];

void solve(){
	cin >> a >> b >> k;

	if(a < b) swap(a, b);

	int tama = a, tamb = b;

	v1.clear(), v2.clear();
	for(int i = 0; i < (int)nt.size(); i++){
		if(a % nt[i] == 0){
			II val = mp(nt[i], 0);
			while(a % nt[i] == 0){
				val.second += 1;
				a /= nt[i];
			}
			v1.pb(val);
		}
		if(nt[i] * nt[i] > a) break;
	}
	if(a > 1){
		v1.pb(mp(a, 1));
	}
	for(int i = 0; i < (int)nt.size(); i++){
		if(b % nt[i] == 0){
			II val = mp(nt[i], 0);
			while(b % nt[i] == 0){
				val.second += 1;
				b /= nt[i];
			}
			v2.pb(val);
		}
		if(nt[i] * nt[i] > b) break;
	}
	if(b > 1){
		v2.pb(mp(b, 1));
	}


	for(int i = 0; i < (int)v1.size(); i++){
		int t = 0;
		for(int j = 0; j < (int)v2.size(); j++){
			if(v2[j].first == v1[i].first){
				t = 1;
				break;
			}
		}
		if(t) continue;
		v2.pb(mp(v1[i].first, 0));
	}

	for(int i = 0; i < (int)v2.size(); i++){
		int t = 0;
		for(int j = 0; j < (int)v1.size(); j++){
			if(v1[j].first == v2[i].first){
				t = 1;
				break;
			}
		}
		if(t) continue;
		v1.pb(mp(v2[i].first, 0));
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	a = tama, b = tamb;

	while(k){
		if(a == 1){
			int val = 0;
			for(int i = 0; i < (int)v2.size(); i++){
				val += v2[i].second;
			}
			if(val >= k){
				cout << "YES" << '\n';
				return;
			}
			else{
				cout << "NO" << '\n';
				return;
			}
		}
		if(b == 1){
			int val = 0;
			for(int i = 0; i < (int)v1.size(); i++){
				val += v1[i].second;
			}
			if(val >= k){
				cout << "YES" << '\n';
				return;
			}
			else{
				cout << "NO" << '\n';
				return;
			}
		}
		if(k == 2){
			cout << "YES" << '\n';
			return;
		}
		if(k == 1){
			int check1 = 1, check2 = 1, check3 = 0, check4 = 0;
			for(int i = 0; i < (int)v1.size(); i++){
				if(v1[i].second < v2[i].second){
					check1 = 0;
					check4 = 1;
				}
				if(v2[i].second < v1[i].second){
					check2 = 0;
					check3 = 1;
				}
			}
			if((check1 & check3) || (check2 & check4)){
				cout << "YES" << '\n';
				return;
			}
			else{
				cout << "NO" << '\n';
				return;
			}
		}
		int pos1 = 0, pos2 = 0;
		for(int i = 0; i < (int)v1.size(); i++){
			if(v1[i].second > v1[pos1].second){
				pos1 = i;
			}
		}
		for(int i = 0; i < (int)v2.size(); i++){
			if(v2[i].second > v2[pos2].second){
				pos2 = i;
			}
		}
		if(max(v1[pos1].second, v2[pos2].second) == 0){
			cout << "NO" << '\n';
			return;
		}
		if(v1[pos1].second > v2[pos2].second){
			v1[pos1].second -= 1;
			a /= v1[pos1].first;
		}
		else{
			v2[pos2].second -= 1;
			b /= v2[pos2].first;
		} 
		k -= 1;
	}

}

void sangnt(){
	for(int i = 0; i <= 100000; i++){
		mark[i] = 1;
	}
	for(int i = 2; i * i <= 100000; i++) {
        if (mark[i]) {
            for(int j = i * i; j <= 100000; j += i) {
                mark[j] = 0;
            }
        }
    }
    for(int i = 2; i <= 100000; i++){
    	if(mark[i]) nt.pb(i);
    }
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	sangnt();
	int T; cin >> T; while(T--){solve();}

	
}