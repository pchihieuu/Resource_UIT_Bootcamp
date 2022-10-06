#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int N = 1e6 + 6;

int fact[N];

/// (a ^ b) % M
int power(int a, int b, int M){
    if(b == 0) return 1;
    if(b == 1) return a;
    int c = power(a, b / 2, M);
    c = (c * c) % M;
    if(b % 2 == 1) c = (c * a) % M;
    return c;
}

/// Modular Multiplicative Inverse
/// Extended Euclid Algorithm
int invEuclid(int a, int m){
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}

/// Euler Phi
int phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            res -= res / i;
        }
    }
    if (n != 1) {
        res -= res / n;
    }
    return res;
}

/// Inverse with M is NOT prime
int invPhi(int a, int M){
    return power(a, phi(M) - 1, M);
}

/// Inverse with M is prime
int invPrime(int a, int M){
    return power(a, M - 2, M);
}

/// Chinese Remainder Theorem
int CRT(vector<pair<int, int> > x){
    int prod = 1;
    for (int i = 0; i < x.size(); i++)
        prod *= x[i].first;

    int result = 0;
    for (int i = 0; i < x.size(); i++) {
        int pp = prod / x[i].first;
        result += x[i].second * invPrime(pp, x[i].first) * pp;
    }
    return result % prod;
}

/// nCr % M, with M is prime
int nCr(int n, int r, int MOD){
    if(r > n) return 0;
    int inv1 = invPrime(fact[r], MOD);
    int inv2 = invPrime(fact[n - r], MOD);
    return (((fact[n] * inv1) % MOD) * inv2) % MOD;
}

vector<int> getRepresentation(int N, int M) {
    vector<int> res;
    while (N > 0) {
        res.push_back(N % M);
        N /= M;
    }
    return res;
}

/**
def lucas(n,r,p): # Using Lucas Theorem to find nCr modulo prime.
	if n < p: return (fact[n]/(fact[r]*fact[n-r]))%p
	ret = 1
	while r: ret,n,r = ret*lucas(n%p,r%p,p)%p, n/p, r/p
	return ret
*/

/// Lucas Theorem
int nCrLucas(int N, int K, int MOD){
    vector<int> n = getRepresentation(N, MOD);
    vector<int> k = getRepresentation(K, MOD);
    long long res = 1;
    for (int i = 0; i < k.size(); ++i) {
        res = (res * nCr(n[i], k[i], MOD)) % MOD;
    }
    return res;
}

void init(){
    fact[0] = 1;
    for(int i = 1; i <= 1000000; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

int32_t main(){
    init();

    /**
    Chinese Remainder Theorem

    37 % 30 = 7  <=> (7 + 30.1) % 30 = 7 => 7

    30 = 2 * 3 * 5

    37 % 2 = 1
    37 % 3 = 1
    37 % 5 = 2

    => X_min = 7 + 30.k (k >= 0)
    => 7

    Time Complexity O(N*logN)
    */
    cout << "Chinese Remainder Theory" << endl;
    vector<pair<int, int> > x;
    x.push_back(make_pair(2, 1));
    x.push_back(make_pair(3, 1));
    x.push_back(make_pair(5, 2));
    cout << "X_min is " << CRT(x) << endl;
    cout << endl;


    /**
    Fermat's little theorem

    GCD(a, m) = 1

    a^-1 ?
    => a^(m - 1) ~ 1 (mod m)
    => a^(m - 2) ~ a^-1 (mod m)

    a^b % m
    => a^(b % (m - 1)) % m
    */

    /**
    Lucas Theorem
    Time Complexity O(log(M))
    */
    cout << "nCr Lucas" << endl;
    cout << nCrLucas(5, 3, 17) << endl;

    /// nCr with small n
    vector<vector<int> > c(1005, vector<int> (1005, 0));
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= i; j++){
            if(i == 0 || j == 0) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
        }
    }
}
