#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double

//#define int long long

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = (1 << 30) - 1;
const long long oo = (1ll << 62) - 1;
const long double PI = 3.1415926535898;

struct Trie
{
    struct node{
        int num, val;
        int child[256 + 5];
    };

    vector<node> tree;
    int res = 0;

    Trie() {}

    int convert(char c){
        if('a' <= c && c <= 'z') return c - 'a';
        else return c - 'A' + 'z' - 'a';
    }

    node newNode(){
        node a;
        a.num = 0;
        a.val = 0;
        for(int i = 0; i < 100; i++)
            a.child[i] = -1;
        return a;
    }

    void newTree(){
        tree.clear();
        tree.push_back(newNode());
    }

    void addWord(string s){
        int index = 0;
        for(int i = 0; i < s.size(); i++){
            tree[index].num++;
            int w = convert(s[i]);
            if(tree[index].child[w] == -1){
                tree.push_back(newNode());
                tree[index].child[w] = tree.size() - 1;
            }
            index = tree[index].child[w];
        }
        tree[index].num++;
        tree[index].val++;
    }

    int countPrefix(string s){
        int index = 0;
        for(int i = 0; i < s.size(); i++){
            int w = convert(s[i]);
            if(tree[index].child[w] == -1) return 0;
            index = tree[index].child[w];
        }
        return tree[index].num;
    }

    int countWord(string s){
        int index = 0;
        for(int  i = 0; i < s.size(); i++){
            int w = convert(s[i]);
            if(tree[index].child[w] == -1) return 0;
            index = tree[index].child[w];
        }
        return tree[index].val;
    }

    void deleteWord(string s){
        if(countPrefix(s) == 0) return;
        int index = 0;
        for(int i = 0; i < s.size(); i++){
            tree[index].num--;
            int w = convert(s[i]);
            index = tree[index].child[w];
        }
        tree[index].num--;
        tree[index].val--;
    }

    void get(int index, int ans){
        for(int i = 0; i < 26; i++){
            if(tree[index].child[i] == -1) res = max(res, ans + tree[index].val);
            else{
                get(tree[index].child[i], ans + tree[index].val);
            }
        }
    }

    void answer(){
        get(0, 0);
        cout << res;
    }
};

int n;
string s;


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    Trie tree;
    tree.newTree();
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s;
        tree.addWord(s);
    }
    tree.answer();
}

