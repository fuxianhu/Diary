#include<bits/stdc++.h>
using namespace std;
__int128 n,K,R,X,C,tot,a[2000005],vis[2000005];
__int128 r=0,c=0,ans=0;
__int128 read(){
	__int128 sum=0;
		__int128 f=1;
	char c=getchar();
	while(c>'9'&&c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		sum=sum*10+(c-'0');
		c=getchar();
	}	
	return sum;
}
struct node{
	__int128 id,val;
}pq[2000005];
void w(__int128 x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)w(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("cross.in","r",stdin);
	freopen("cross.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	n=read();
	K=read();
	R=read();
	X=read();
	C=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	__int128 sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];		
		if(sum){
			pq[++tot].id=i,pq[tot].val=(n-i+1)*C+(n-i+1)*R;
		}
		sum--;
		if(sum<0)sum=0;
	}
	__int128 l=1;
	for(int i=1;i<=n;i++){
		r+=a[i];
		int k=K;
		while(pq[l].id<i&&l<=tot)l++;
		if(r&&K){
			K--;
			r--;
			c++;
		}
		else if(!r&&K){
			if(l+K-1<=tot&&pq[l+K-1].val<(n-i+1)*C){
				K--,c++;
			}	
			if(l+K-1>tot){
				K--,c++;
			}
		}
		ans-=r*R;
		ans+=X;
		ans+=c*C;
	}
	w(ans);
	return 0;
}
