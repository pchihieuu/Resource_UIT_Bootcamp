	
#include<bits/stdc++.h>
using namespace std;
#define FORE(i, a, b) for(int i=(a), _b=(b); i<=_b; i++)
 
const int DBG = 0;
const int HOME = 0;
 
int m, n;
int a[202][202], c[202][202];
int nextr[202][202], nextc[202][202];
 
inline int sum(int u, int v){
   return a[u-1][v]+ a[u][v-1]+a[u][v+1]+a[u+1][v];
}
 
bool Try(int u, int v){
   int t, u2,v2;

   if(u==m || v==1){
         if(u + v >= n){ 
         	v2 = n; 
         	u2 = u+v+1-v2;
         }
         else { 
         	u2 = 1; 
         	v2= u+v+1-u2;
         }
   }
   else{ 
   		u2 = u+1; 
   		v2 = v-1;
   }
   
   if(u==m && v==n){
      a[u][v]=0; t=c[u-1][v-1]-sum(u-1, v-1);
      if(t<0 || t>1) return false;
      a[u][v]=t; return true;
   }
   if(u==1){
      a[u][v]=0; if(Try(u2, v2)) return true;
      a[u][v]=1; if(Try(u2, v2)) return true;
      return false;
   }
   if(v==1){
      a[u][v]=0; if(Try(u2, v2)) return true;
      a[u][v]=1; if(Try(u2, v2)) return true;
      return false;
   }
 
   a[u][v] = 0; t = c[u-1][v-1]-sum(u-1, v-1);
   if(t<0 || t>1) return false;
   a[u][v] = t;
   if(u == m && sum(u, v-1) != c[u][v-1]) return false;
   if(v == n && sum(u-1, v) != c[u-1][v]) return false;
   if(Try(u2, v2)) return true;
   return false;
}
 
int main(){
   if(HOME){
      freopen("mines.inp", "r", stdin);
      freopen("mines.out", "w", stdout);
   }
   
   scanf("%d %d", &m, &n);
   FORE(i, 1, m) FORE(j, 1, n) scanf("%d", &c[i][j]);
   memset(a, 0, sizeof a);
 
   FORE(i, 0, 1){ a[1][1]=i; if(Try(1,2)) break; }
   
   FORE(i, 1, m) FORE(j, 1, n)
      printf("%d%c", a[i][j], j==n?'\n':' ');
   return 0;
}