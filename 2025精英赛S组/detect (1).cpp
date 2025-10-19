#include<iostream>
#include<cstdio>
int n;
int main()
{
	std::freopen("detect.in","r",stdin);
	std::freopen("detect.out","w",stdout);
    std::cin>>n;
    std::cout<<std::max(n-1,1)<<" 1\n";
    for(int i=2;i<=n;i++)
    {
    	if(i==2||i==3) std::cout<<"1 "<<i<<"\n";
    	else std::cout<<i-2-(i%2)<<" "<<i<<"\n";
	}
	return 0;
}
