#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=998244353;
const int N=1e6+10;
int a[N],cnt[N];
signed main(){
	int n;
	cin>>n;
	a[1]=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			cnt[j]++;
		}
	}
	int sum=a[1];
	for(int i=2;i<=n;i++){
		a[i]=(cnt[i]+sum)%p;
		sum=(sum+a[i])%p; 
	}
	cout<<a[n]%p<<endl;
}