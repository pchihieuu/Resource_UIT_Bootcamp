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
int BD = 1, KT = 50;

string path_folder = "C:\\Users\\nqhho\\Desktop\\CP\\UIT-ALGO-BOOTCAMP\\AlgoBootcamp_Contest\\2021-2022\\ThayTung",
folder = "\\MARATHON",

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

    if(iTest <= 30){
        int n = Rand(1, 23);
        cout << n << '\n';
        for(int i = 1; i <= n; i++){
            int res_s = Rand(0, 59);
            int res_m = Rand(0, 59);
            cout << setw(2) << setfill('0') << res_m << ":";
            cout << setw(2) << setfill('0') << res_s << '\n';
        }
    }
    else{
        if(iTest <= 40){
            cout << 500 << '\n';
            for(int i = 1; i <= 500; i++){
                int res_s = Rand(0, 59);
                int res_m = Rand(0, 1);
                cout << setw(2) << setfill('0') << res_m << ":";
                cout << setw(2) << setfill('0') << res_s << '\n';
            }
        }
        else{
            cout << 1000 << '\n';
            for(int i = 1; i <= 1000; i++){
                int res_s = Rand(0, 59);
                int res_m = 0;
                cout << setw(2) << setfill('0') << res_m << ":";
                cout << setw(2) << setfill('0') << res_s << '\n';
            }
        }
    }


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
    int sum = 0;
    for(int i = 1; i <= n; i++){
        int a, b;
        char c;
        ip >> a >> c >> b;
        sum += a * 60 + b;
    }
    int res_s = sum % 60;
    int res_m = (sum / 60) % 60;
    int res_h = sum / 3600;
    cout << setw(2) << setfill('0') << res_h << ":";
    cout << setw(2) << setfill('0') << res_m << ":";
    cout << setw(2) << setfill('0') << res_s;


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
