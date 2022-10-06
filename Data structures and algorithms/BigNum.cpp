#include<bits/stdc++.h>
using namespace std;

#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1005;

void fix(vector<int> &a){
    a.push_back(0);
    for(int i = 0; i < (int)a.size() - 1; i++){
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
        if(a[i] < 0){
            a[i] += 10;
            a[i + 1] -= 1;
        }
    }
    while(a.size() > 1 && a.back() == 0) a.pop_back();
}

vector<int> operator + (vector<int> a, vector<int> b){
    while(a.size() < b.size()) a.push_back(0);
    for(int i = 0; i < (int)b.size(); i++){
        a[i] += b[i];
    }
    fix(a);
    return a;
}

vector<int> operator - (vector<int> a, vector<int> b){
    for(int i = 0; i < (int)b.size(); i++){
        a[i] -= b[i];
    }
    fix(a);
    return a;
}

vector<int> operator * (vector<int> a, vector<int> b){
    vector<int> c = vector<int> (a.size() + b.size(), 0);
    for(int i = 0; i < (int)a.size(); i++){
        for(int j = 0; j < (int)b.size(); j++){
            c[i + j] += a[i] * b[j];
        }
    }
    fix(c);
    return c;
}

int compare(vector<int> a, vector<int> b){
    if(a.size() > b.size()) return 1;
    if(a.size() < b.size()) return 0;
    for(int i = (int)a.size() - 1; i >= 0; i--){
        if(a[i] > b[i]) return 1;
        if(b[i] > a[i]) return 0;
    }
    return 1;

}

vector<int> convert(string s){
    vector<int> a;
    for(int i = (int)s.size() - 1; i >= 0; i--){
        a.push_back(s[i] - '0');
    }
    return a;

}

void write(vector<int> a){
    for(int i = (int)a.size() - 1; i >= 0; i--){
        cout << a[i];
    }
}

int32_t main(){
    //freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    vector<int> a = convert(s1);
    vector<int> b = convert(s2);

    write(a + b); cout << '\n';

    if(compare(a, b)){
        write(a - b);
        cout << '\n';
    }
    else{
        cout << '-'; write(b - a);
        cout << '\n';
    }

    write(a * b);

}
