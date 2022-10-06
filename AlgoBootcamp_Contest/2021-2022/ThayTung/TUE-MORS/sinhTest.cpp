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
int BD = 1, KT = 20;

string path_folder = "C:\\Users\\nqhho\\Desktop\\ThayTung",
folder = "\\TUE-MORS",

path = path_folder + folder,
path_in = path_folder + folder + "\\in",
path_out = path_folder + folder + "\\out";



//RANDOM
/**************************************************/
int Rand(int l, int r) {
    return l + rand() % (r - l + 1);
}

const int I5 = 1e5;
const int I12 = 1e12;
const int I15 = 1e15;
const int I18 = 1e18;
const int I17 = 1e17;

int _N[] = {18, 1, 1, 4, 3, 8, 2,  I12, I18, I17, I15, I18};
int _K[] = {6,  1, 3, 2, 7, 4, I5, 1,   1,   3,   8,   I5};


//SINH TEST
/**************************************************/
void INPUT(int iTest){
    ostringstream in;
    in << "input" << iTest << ".txt";
    string INPUT = path_in + "\\" + in.str();
    freopen(INPUT.c_str(),"w",stdout);
    /**********CODE TEST***********/
    if(iTest <= 12){
        cout << _N[iTest - 1] << " " << _K[iTest - 1];
    }
    else{
        int n = Rand(1, I5);
        int k = Rand(1, I5);
        cout << I15 + n << " " << k;
    }


}


//SINH DAP AN
/**************************************************/

int backTrack(int col, int l, int r, int pos){
    if(l == r) return col;
    int mid = (l + r) / 2;
    if(pos <= mid) return backTrack(col, 1, mid, pos);
    else return backTrack(col ^ 1, 1, mid, pos - mid);
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

    int n, k;
    ip >> n >> k;
    vector<int> res;
    for(int i = 1; i <= k; i++){
        int pos = n + i - 1;
        for(int j = 0; j < 63; j++){
            int val = 1ll << j;
            if(val >= pos){
                res.push_back(backTrack(0, 1, val, pos));
                break;
            }
        }
    }
    for(int i: res) cout << i;

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
