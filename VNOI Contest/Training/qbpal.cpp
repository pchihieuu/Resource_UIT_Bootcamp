#include<bits/stdc++.h>
using namespace std;

const int N = 120 + 5;

void fix(vector<int> &a){
	a.push_back(0);
	for(int i = 0; i < (int)a.size() - 1; i++){
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
		if(a[i] < 0){
			a[i] += 10;
			a[i + 1] -= 1;
		}
	}
	while((int)a.size() > 1 && a.back() == 0){
		a.pop_back();
	}
}

vector<int> operator + (vector<int> a, vector<int> b){
	while((int)a.size() < (int)b.size())
		a.push_back(0);
	for(int i = 0; i < (int)b.size(); i++){
		a[i] += b[i];
	}
	fix(a);
	return a;
}

vector<int> operator - (vector<int> a, vector<int> b){
	for(int i = 0; i < (int)b.size(); i++){
		a[i] -= b[i];
	}
	fix(a);
	return a;
}

vector<int> f[N][N];
string s;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	int n = s.size();
	s = '@' + s;

	for(int i = 1; i <= n; i++){
		f[i][i] = {1};
	}
	for(int i = 2; i <= n; i++){
		for(int l = 1; l <= n; l++){
			int r = l + i - 1;
			f[l][r] = f[l][r] + f[l + 1][r] + f[l][r - 1] - f[l + 1][r - 1];
			if(s[l] == s[r]){
				f[l][r] = f[l][r] + f[l + 1][r - 1] + vector<int>{1};;
			}
		}
	}

	vector<int> res = f[1][n];
	for(int i = (int)res.size() - 1; i >= 0; i--){
		cout << res[i];
	}

}