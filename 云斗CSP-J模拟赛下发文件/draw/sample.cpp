#include<bits/stdc++.h>
using namespace std;
unsigned int sd,sd2=998244353,sd3=114514;
unsigned int my_rand()
{
	sd^=(sd2^sd3),sd2^=sd3+233,sd3^=sd*1945;
	return (sd^sd2^sd3^20041025)+sd*sd2*sd3;
}
const int mod=1e9+7,mx=1e9;
int n,m,a[5000010],ans;
void File(string s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
	return;
}
void input()
{
	cin>>n>>m>>sd;
	for(int i=1;i<=n;i++)a[i]=my_rand()%mx+1;
	return;
}
void init()
{
	//do something or do noting
	
	return;
}
int get_ans(int l,int r)
{
	//do something
	
	return 0/*your answer to this question*/;
}
void work()
{
	for(int i=1,l,r;i<=m;i++)
	{
		l=my_rand()%n+1,r=my_rand()%n+1;
		if(l>r)l^=r^=l^=r;
		ans=(ans+get_ans(l,r))%mod;
	}
	return;
}
void print()
{
	cout<<ans<<'\n';
	return;
}
int main()
{
	File("draw");
	input();
	init(); 
	work();
	print();
	return 0;
}
