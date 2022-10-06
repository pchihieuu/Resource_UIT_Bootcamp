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

//KHOI TAO
/**************************************************/
int BD = 1, KT = 100;

string path_folder = "C:\\Users\\nqhho\\Desktop\\CP\\UIT-ALGO-BOOTCAMP\\AlgoBootcamp_Contest\\2021-2022\\ThayTung",
folder = "\\CHOCOLATE",

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
    if(iTest <= 60){
        int n = Rand(1, 50);
        int m = Rand(1, 50);
        cout << n << " " << m;
    }
    else{
        if(iTest <= 90){
            int n = Rand(100, 1000000000);
            int m = Rand(100, 1000000000);
            cout << n << " " << m;
        }
        else{
            int n = Rand(100000000, 1000000000);
            int m = Rand(100000000, 1000000000);
            cout << n << " " << m;
        }


    }
}


//SINH DAP AN
/**************************************************/

int cal(int n, int m){
    while((n & 1) == 0){
        n >>= 1;
        m <<= 1;
    }
    return (n + m) * 2;
}

void OUTPUT(int iTest){
    ostringstream in, out;
    in << "input" << iTest << ".txt";
    string INPUT = path_in + "\\" + in.str();
    ifstream ip(INPUT.c_str());
    out << "output" << iTest << ".txt";
    string OUTPUT = path_out + "\\" + out.str();
    freopen(OUTPUT.c_str(), "w", stdout);
    /**********CODE SOLUTION***********/
    int n, m;
    ip >> n >> m;
    cout << max(cal(n, m), cal(m, n));


}

int32_t main()
{
    mkdir(path.c_str());

    srand(time(NULL));
    mkdir(path_in.c_str());
    for (int iTest = BD; iTest <= KT; iTest++){
        INPUT(iTest);
    }

    mkdir(path_out.c_str());
    for(int iTest = BD; iTest <= KT; iTest++){
        OUTPUT(iTest);
    }
}
