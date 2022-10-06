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
folder = "\\PACKING",

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

int A[] = {1, 1, 2, 2, 1, 2, 3, 3, 2, 1000000000, 20000000};
int B[] = {1, 2, 1, 2, 3, 3, 2, 3, 10, 1000000000, 40000000};

//SINH TEST
/**************************************************/
void INPUT(int iTest){
    ostringstream in;
    in << "input" << iTest << ".txt";
    string INPUT = path_in + "\\" + in.str();
    freopen(INPUT.c_str(),"w",stdout);
    /**********CODE TEST***********/
    if(iTest <= 11){
        cout << A[iTest - 1] << '\n';
        cout << B[iTest - 1];
    }
    else{
        if(iTest <= 30){
            int a = Rand(50, 100);
            int b = Rand(50, 100);
            cout << a << '\n';
            cout << b;
        }
        else{
            int a = Rand(700000000, 1000000000);
            int b = Rand(700000000, 1000000000);
            cout << a << '\n';
            cout << b;
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
    int a, b;
    ip >> a >> b;
    if((a + b) % 3 != 0){
        cout << -1;
        return;
    }
    int val = (a + b) / 3;

    if(a < val || b < val){
        cout << -1;
        return;
    }

    cout << a - val << " " << b - val;


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
