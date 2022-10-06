#include<bits/stdc++.h>
using namespace std;

#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ld long double

typedef pair<int, int> II;
typedef pair<int, II> III;

/// 4 directions
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

/// Default long long max => 1e18
const int INF = 1e18;

/// Default MOD => 1e9 + 7
const int MOD = 1e9 + 7;

/// Input limit
const int N = 1e5 + 5;

int compare(vector<int> a, vector<int> b){
    if(b.size() < a.size()) return 1;
    if(a.size() < b.size()) return -1;
    for(int i = 0; i < a.size(); i++){
        if(a[i] < b[i]) return -1;
        if(b[i] < a[i]) return 1;
    }
    return 0;
}

int mark[N];
vector<int> digit[15];

vector<int> xoa(int k, vector<int> b){
    b.push_back(9);
    for(int i = 0; i <= 9; i++)
        digit[i].clear();

    for(int i = b.size() - 1; i >= 0; i--){
        mark[i] = 0;
        digit[b[i]].push_back(i);
    }

    int pos = 0;
    int i = 0;
    int cnt = 0;
    while(i < b.size()){
        for(int val = 9; val >= 0; val--){

            while(digit[val].size() && digit[val].back() < i)
                digit[val].pop_back();

            if(digit[val].size() && digit[val].back() - i <= k){
                //cout << k << " " << val << endl;
                pos = digit[val].back();
                break;
            }
        }

        mark[pos] = 1;

        if(pos > i){
            k -= pos - i;
            i = pos + 1;
        }
        else{
            i += 1;
        }
    }

    b.pop_back();

    vector<int> temp;
    for(int i = 0; i < b.size(); i++){
        if(mark[i] == 0) continue;
        temp.push_back(b[i]);
    }
    reverse(temp.begin(), temp.end());
    while(temp.size() > 1 && temp.back() == 0) temp.pop_back();
    reverse(temp.begin(), temp.end());
    return temp;
}

int s[10][N];

int countVal(int x, int l, int r){
    if(l > r) return 0;
    if(l == 0) return s[x][r];
    else return s[x][r] - s[x][l - 1];
}

int res = 0;
vector<int> xoa(vector<int> a, vector<int> b){
    int check = compare(a, b);
    if(check >= 0) return b;

    int k = b.size() - a.size() + 1;

    // Very hard
    // =
    for(int i = 0; i <= 9; i++){
        s[i][0] = 0;
    }
    s[b[0]][0] = 1;
    for(int i = 1; i < b.size(); i++){
        for(int j = 0; j <= 9; j++){
            if(j == b[i]){
                s[j][i] = s[j][i - 1] + 1;
            }
            else s[j][i] = s[j][i - 1];
        }
    }

    int pos = 0;
    int mask1 = -1, mask2 = 0, mask3 = 0;
    for(int i = 0; i < b.size(); i++){
        if(b[i] == a[pos]){

            if(pos == a.size() - 1){
                res += k - 1;
                return a;
            }

            int t = a.size() - pos - 1 - 1;
            int l = i + 1, r = b.size() - 1 - t;

            for(int j = a[pos + 1] - 1; j >= 0; j--){
                if(countVal(j, l, r)){
                    mask1 = i;
                    mask2 = pos;
                    mask3 = j;
                    break;
                }
            }
            pos += 1;
        }
    }

    vector<int> temp, temp2;
    if(mask1 != -1){
        for(int i = 0; i <= mask2; i++){
            temp.push_back(a[i]);
        }
        temp.push_back(mask3);

        int vt = 0;
        for(int i = mask1 + 1; i < b.size(); i++){
            if(b[i] == mask3){
                vt = i + 1;
                break;
            }
        }
        for(int i = vt; i < b.size(); i++){
            temp2.push_back(b[i]);
        }
        int val = vt - temp.size();
        temp2 = xoa(k - 1 - val, temp2);

        for(int i: temp2) temp.push_back(i);
        check = compare(a, temp);
        if(check >= 0){
            //cout << "Check1: " << k - 1 << endl;
            res += k - 1;
            return temp;
        }
    }
    else{
        mask3 = -1;
        int t = a.size() - 1;
        int l = 0, r = b.size() - 1 - t;
        for(int i = a[0] - 1; i >= 0; i--){
            if(countVal(i, l, r)){
                mask3 = i;
                break;
            }
        }
        if(mask3 != -1){
            temp.push_back(mask3);

            int vt = 0;
            for(int i = 0; i < b.size(); i++){
                if(b[i] == mask3){
                    vt = i + 1;
                    break;
                }
            }
            for(int i = vt; i < b.size(); i++){
                temp2.push_back(b[i]);
            }
            int val = vt - temp.size();
            temp2 = xoa(k - 1 - val, temp2);
            for(int i: temp2) temp.push_back(i);

            check = compare(a, temp);
            if(check >= 0){
                //cout << "Check2: " << k - 1 << endl;
                res += k - 1;
                return temp;
            }
        }
    }


    // Easy
    // <
    temp = xoa(k, b); //for(int i: temp) cout << i; cout << endl;
    check = compare(a, temp);
    if(check >= 0){
        res += k;
        //cout << "Check3: " << k << endl;
        return temp;
    }

    return {};
}

int n;
vector<int> a[N];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(char c: s){
            a[i].push_back(c - '0');
        }
    }
    if(n == 1){
        cout << 0;
        return;
    }

    for(int i = n - 1; i >= 1; i--){
        a[i] = xoa(a[i + 1], a[i]);
        if(a[i].size() == 0){
            cout << -1;
            return;
        }
    }

    cout << res;
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T = 1;
	//cin >> T;
	while(T--){solve();}
}
