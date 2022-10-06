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

int n, m, Num[N], Low[N], cnt = 0;
vector<int> a[N], e[N];
stack<int> st;
int Count = 0;

vector<int> x[N];
int val[N];
int mark[N];
int c[N];
int dd[N];

void visit(int u) {
    Low[u] = Num[u] = ++cnt;
    st.push(u);

    for (int v : a[u])
        if (Num[v])
            Low[u] = min(Low[u], Num[v]);
        else {
            visit(v);
            Low[u] = min(Low[u], Low[v]);
        }

    if (Num[u] == Low[u]) {
        Count++;
        int v;
        do {
            v = st.top();
            x[Count].push_back(v);
            val[v] = Count;
            st.pop();
            Num[v] = Low[v] = INF;
        } while (v != u);
    }
}

int dfs(int u){
	if(c[u]) return c[u];
	if(mark[u]) return 0;
	int res = 0;
	mark[u] = 1;
	for(int v: e[u]){
		int val = dfs(v);
		res += val;
	}
	if(res == 0){
		return c[u] = -1e9;
	}
	return c[u] = res;
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
    	a[i].clear();
    	e[i].clear();
    	dd[i] = 0;
    	mark[i] = 0;
    	x[i].clear();
    	val[i] = i;
    	c[i] = 0;
    	Num[i] = 0;
    	Low[i] = 0;
    }
    while(st.size()) st.pop();
    cnt = 0;
    Count = 0;

    c[1] = 1;
    for(int i = 1; i <= m; i++){
    	int x, y;
    	cin >> x >> y;
    	if(x == y) dd[x] = 1;
    	else a[x].push_back(y), e[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
        if (!Num[i]) visit(i);	

    for(int i = 1; i <= n; i++){
    	if(mark[i] == 0) dfs(i);
    }


    for(int i = 1; i <= n; i++){
    	if(c[i] < 0) c[i] = 0;
    }

	queue<int> q;

    for(int i = 1; i <= n; i++){
    	mark[i] = 0;
    	if((dd[i] || (int)x[val[i]].size() > 1) && c[i] > 0){
    		q.push(i);
    		c[i] = -1;
    		mark[i] = 1;
    	}
    }



    while(q.size()){
    	int u = q.front();
    	q.pop();
    	for(int v: a[u]){
    		if(mark[v]) continue;
    		mark[v] = 1;
    		if(c[v] > 0){
    			c[v] = -1;
    			q.push(v);
    		}

    	}
    }

    for(int i = 1; i <= n; i++){
    	cout << c[i] << " ";
    }
    cout << '\n';

}


int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}

	
}