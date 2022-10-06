#include<bits/stdc++.h>
using namespace std;

vector<int> a[10];
int S = 1, T = 2;
int val = 0;

vector<int> tv;

int dfs(int u, int d){
	if(d == 0){
		if(u == 2){
			for(int i: tv){
				cout << i << " ";
			}
			cout << endl;
			return 1;
		}
		else return 0;
	}

	
	int res = 0;
	for(int v: a[u]){
		tv.push_back(v);
		res += dfs(v, d - 1);
		tv.pop_back();
	}
	
	return res;
}

int main(){
	for(int i = 1; i <= 3; i++){
		for(int j = 4; j <= 6; j++){
			a[i].push_back(j);
			a[j].push_back(i);
		}
	}
	tv.push_back(1);
	cout << dfs(1, 6);
}