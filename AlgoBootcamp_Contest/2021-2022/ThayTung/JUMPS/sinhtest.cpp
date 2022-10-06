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
folder = "\\JUMPS",

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
    if(iTest <= 20){
        int n = Rand(1, 100);
        cout << n << '\n';
        for(int i = 1; i <= n; i++){
            int val = Rand(1, 10);
            cout << val << " ";
        }
    }
    else{
        if(iTest <= 40){
            cout << 10 << '\n';
            for(int i = 1; i <= 5; i++){
                int val = Rand(1, 100000);
                cout << val << " ";
            }
            for(int i = 5 + 1; i <= 10; i++){
                int val = Rand(50000, 100000);
                cout << val << " ";
            }
        }
        else{
            int n = 100;
            int s = 1000000;
            cout << n << '\n';

            for(int i = 1; i <= 25; i++){
                int val = Rand(1, 1000);
                cout << val << " ";
                s -= val;
            }
            for(int i = 25 + 1; i <= 75; i++){
                int val = Rand(100, 10000);
                cout << val << " ";
                s -= val;
            }
            for(int i = 75 + 1; i <= 99; i++){
                int val = Rand(1, 1000);
                cout << val << " ";
                s -= val;
            }
            if(iTest == 50){
                cout << s << " ";
            }
            else cout << Rand(1, s) << " ";
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
    vector<int> mas(n);
    int64_t s = 0;
    for(int &x: mas){
        ip >> x;
        s += x;
    }
    sort(mas.begin(), mas.end());

    vector<int> dp(s + 1, 0);
    s = 0;
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = s; j >= 0; j--){
            if(dp[j]) dp[j + mas[i]] = 1;
        }
        s += mas[i];
    }
    int cnt = 0;
    int64_t ans = 0;
    for(int i = s; i >= 0; i--){
        if(dp[i]){
            cnt += 1;
            ans += s + 1 - i;
        }
        else ans += cnt;
    }
    cout << ans;


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
