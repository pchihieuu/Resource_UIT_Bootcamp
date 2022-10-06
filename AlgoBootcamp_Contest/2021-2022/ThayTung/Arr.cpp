#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q;
int a[N];

struct node{
    int mask, left1, right1, len;
    long long val;
    node(){}
    node(int mask, int left1, int right1, int len, long long val){
        this->mask = mask, this->left1 = left1, this->right1 = right1, this->len = len, this->val = val;
    }
};
node st[27][4 * N];

node mergeNode(const node &a, const node &b){
    if(a.len == 0) return b;
    if(b.len == 0) return a;

    return node(a.mask ^ b.mask, (a.mask == 1) ? (a.left1 + (b.len - b.left1)) : (a.left1 + b.left1),
                (b.mask == 1) ? (b.right1 + (a.len - a.right1)) : (b.right1 + a.right1),
                a.len + b.len, a.val + b.val + (1LL * (a.len - a.right1) * b.left1) + (1LL * a.right1 * (b.len - b.left1)));
}

void build(int t, int id, int l, int r){
    if(l == r){
        if(a[l] >> t & 1) st[t][id] = node(1, 1, 1, 1, 1LL);
        else st[t][id] = node(0, 0, 0, 1, 0LL);
        return;
    }
    int m = (l + r) >> 1;
    build(t, id << 1, l, m);
    build(t, id << 1 | 1, m + 1, r);
    st[t][id] = mergeNode(st[t][id << 1], st[t][id << 1 | 1]);
}

void update(int t, int pos, int val){
    int id = 1, l = 1, r = n;
    while(l < r){
        int m = (l + r) >> 1;
        if(pos <= m){
            id = id * 2;
            r = m;
        }
        else{
            id = id * 2 + 1;
            l = m + 1;
        }
    }

    if(val >> t & 1) st[t][id] = node(1, 1, 1, 1, 1LL);
    else st[t][id] = node(0, 0, 0, 1, 0LL);

    while(id){
        id >>= 1;
        st[t][id] = mergeNode(st[t][id << 1], st[t][id << 1 | 1]);
    }
}

pair<int, pair<int, int> > s[N];

node query(int t, int u, int v){
    node res = node(0, 0, 0, 0, 0LL);
    s[1] = {1, {1, n}};
    int i = 1;
    while(i){
        int id = s[i].first, l = s[i].second.first, r = s[i].second.second;
        i--;
        if(l > v || u > r) continue;
        if(u <= l && r <= v){
            res = mergeNode(res, st[t][id]);
            continue;
        }
        int m = (l + r) >> 1;
        i++;
        s[i] = {id << 1 | 1, {m + 1, r}};
        i++;
        s[i] = {id << 1, {l, m}};
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int t = 0; t < 27; t++){
        build(t, 1, 1, n);
    }
    while(q--){
        int key, u, v;
        cin >> key >> u >> v;
        if(key == 1){
            for(int t = 0; t < 27; t++){
                if((a[u] >> t & 1) == (v >> t & 1)) continue;
                update(t, u, v);
            }
            a[u] = v;
        }
        else{
            long long res = 0;
            for(int t = 0; t < 27; t++){
                node ans = query(t, u, v);
                res += ans.val * (1 << t);
            }
            cout << res << '\n';
        }
    }
}
