#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back

const int N = 1005;

int k, m, n;

int a[N][N];
int bia[20][10];
int mark[300];
int dd[N][N], re[N][N];

vector<vector<int> > dx = {
	{0, 1, 2, 3, 0, 1, 2, 3},
	{0, 0, 0, 0, 1, 1, 1, 1}
};
vector<vector<int> > dy = {
	{0, 0, 0, 0, 1, 1, 1, 1},
	{0, 1, 2, 3, 0, 1, 2, 3}
};

int CHECK = 0;

void restore(int i, int j, int type){
	for(int t = 0; t < 8; t++){
		int u = i + dx[type][t];
		int v = j + dy[type][t];
		if(u < 1 || u > m || v < 1 || v > n) return;
		dd[u][v] = re[u][v];
	}
}

int check(int i, int j, int type){
	int bit = 0, val = 0;
	for(int t = 0; t < 8; t++){
		int u = i + dx[type][t];
		int v = j + dy[type][t];
		if(u < 1 || u > m || v < 1 || v > n) return 0;
		if(dd[u][v]) return 0;
		if(a[u][v]) val += 1 << bit;
		bit += 1;
	}

	if(mark[val] == 0) return 0;
	for(int t = 0; t < 8; t++){
		int u = i + dx[type][t];
		int v = j + dy[type][t];
		re[u][v] = dd[u][v];
		dd[u][v] = mark[val];
	}
	return 1;
}

void get_result(){
	int key = 1;
	for(int u = 1; u <= m; u++){
		if(key == 0) break;
		for(int v = 1; v <= n; v++){
			if(dd[u][v] == 0){
				key = 0;
				break;
			}
		}
	}
	if(key){
		CHECK = 1;
		for(int u = 1; u <= m; u++){
			for(int v = 1; v <= n; v++){
				cout << dd[u][v] << " ";
			}
			cout << '\n';
		}
	}
}

void backtrack(int i, int j){
	if(CHECK) return;

	if(i >= m) return;

	if(dd[i][j]){
		if(j + 2 > n) backtrack(i + 2, 1);
		else backtrack(i, j + 2);
		return;
	}

	for(int t = 0; t < 2; t++){
		int kt = check(i, j, t);
		if(kt){
			//cout << "type = " << t << " " << "i = " << i << " " << "j = " << j << " " << "kt = " << kt << endl;
			if(t == 0){
				if(i + 2 >= n + 1 && j + 4 >= m + 1) get_result();
				else{
					if(j + 2 > n) backtrack(i + 2, 1);
					else backtrack(i, j + 2);
				} 
			}
			else{
				if(i + 4 >= n + 1 && j + 2 >= m + 1) get_result();
				else{
					if(j + 2 > n) backtrack(i + 2, 1);
					else backtrack(i, j + 2);
				}
			}
			restore(i, j, t);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> k >> m >> n;
	for(int i = 1; i <= k; i++){
		int u = 1, v = 1;
		for(int j = 1; j <= 8; j++){
			char c;
			cin >> c;
			if(v > 2){
				u += 1;
				v = 1;
			}
			bia[u][v] = c - '0';
			v += 1;
		}

		//1
		u = 1, v = 1;
		int j = 0, val = 0;
		while(v <= 2){
			if(bia[u][v]) val += 1 << j;
			j += 1;
			u += 1;
			if(u > 4){
				u = 1;
				v += 1;
			}
		}
		mark[val] = i;

		//2
		u = 1, v = 2;
		j = 0, val = 0;
		while(v >= 1){
			if(bia[u][v]) val += 1 << j;
			j += 1;
			u += 1;
			if(u > 4){
				u = 1;
				v -= 1;
			}
		}
		mark[val] = i;

		//3
		u = 4, v = 1;
		j = 0, val = 0;
		while(v <= 2){
			if(bia[u][v]) val += 1 << j;
			j += 1;
			u -= 1;
			if(u < 1){
				u = 4;
				v += 1;
			}
		}
		mark[val] = i;

		//4
		u = 4, v = 2;
		j = 0, val = 0;
		while(v >= 1){
			if(bia[u][v]) val += 1 << j;
			j += 1;
			u -= 1;
			if(u < 1){
				u = 4;
				v -= 1;
			}
		}
		mark[val] = i;
	}

	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			char c;
			cin >> c;
			a[i][j] = c - '0';
		}
	}

	backtrack(1, 1);
	if(CHECK == 0){
		cout << "KHONG" << '\n';
	}
}

/**
3 6 8
10011000
10000101
01011010
11001010
00110010
10010100
01100101
10011100
00000011
*/