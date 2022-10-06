#include<bits/stdc++.h>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <stdio.h>
#include<io.h>
#include <cstdlib>
#include <ctime>
#include<string>

#define int long long
using namespace std;

const int INF = 1e18;

//KHOI TAO
/**************************************************/
int BD = 1, KT = 50;

string path_folder = "C:\\Users\\nqhho\\Desktop\\CP\\UIT-ALGO-BOOTCAMP\\AlgoBootcamp_Contest\\2021-2022\\ThayTung",
folder = "\\BUTTERFLY",

path = path_folder + folder,
path_in = path_folder + folder + "\\in",
path_out = path_folder + folder + "\\out";



//RANDOM
/**************************************************/
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

int Rand(int l, int r) {
    int length = r - l + 1;
    int ans = l + ((1ll * rd() * rd()) % length + length) % length;

}


//SINH TEST
/**************************************************/
void INPUT(int iTest){
    ostringstream in;
    in << "input" << iTest << ".txt";
    string INPUT = path_in + "\\" + in.str();
    freopen(INPUT.c_str(),"w",stdout);
    /**********CODE TEST***********/



}


//SINH DAP AN
/**************************************************/
void OUTPUT(int iTest){
    ostringstream in, out;
    in << "input" << iTest << ".txt";
    string INPUT = path_in + "\\" + in.str();
    ifstream ip(INPUT.c_str());
    out << "output" << iTest << ".txt";
    string OUTPUT = path_out + "\\" + out.str();
    freopen(OUTPUT.c_str(), "w", stdout);
    /**********CODE SOLUTION***********/

    int n;
    ip >> n;
    vector<vector<int> > graph(n);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        ip >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> dp(n);
    vector<int> nearest(n);
    function<void(int, int, int)> dfs = [&](int v, int p, int d){
        nearest[v] = INF;
        int cnt = 0;
        for(int to: graph[v]){
            if(to != p){
                ++cnt;
                dfs(to, v, d + 1);
                nearest[v] = min(nearest[v], nearest[to] + 1);
                dp[v] += dp[to];
            }
        }
        if(!cnt) nearest[v] = 0;
        if(nearest[v] <= d) dp[v] = 1;
    };
    dfs(0, 0, 0);
    cout << dp[0];
}

int32_t main()
{
//    mkdir(path.c_str());
//
//    srand(time(NULL));
//    mkdir(path_in.c_str());
//    for (int iTest = BD; iTest <= KT; iTest++){
//        INPUT(iTest);
//    }

    mkdir(path_out.c_str());
    for(int iTest = BD; iTest <= KT; iTest++){
        OUTPUT2(iTest);
    }
    return 0;
}
