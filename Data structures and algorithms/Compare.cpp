#include<bits/stdc++.h>
using namespace std;

struct node{
	int x, y, z;
	node(){}
	node(int x, int y, int z){
		this->x = x; this->y = y; this->z = z;
	}
};

struct compare{
	bool operator() (const node a, const node b) const{
		if(a.x != b.x) return a.x < b.x;
		else{
			if(a.y != b.y) return a.y < b.y;
			else{
				return a.z < b.z;
			}
		}
	}
};

set<int> Set;
set<int, greater<int> > Set_max;
set<node, compare> Set_compare; //set min

map<int, int> Map;
map<int, int, greater<int> > Map_max;
map<node, int, compare> Map_compare; //map min

priority_queue<int> heap_max;
priority_queue<int, vector<int>, greater<int> > heap_min;
priority_queue<node, vector<node>, compare> heap_compare; //heap max

int main(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		Set_compare.insert({x, 0, 0});
		
	}

	for(auto it: Set_compare){
		cout << it.x << endl;
	}
}