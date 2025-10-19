#include <iostream>
using namespace std;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int n;
	cin>>n;
	if(n==1){
		cout<<"1 1";
		return 0;
	}
	printf("%d 1\n",n-1);
	for(int i=1;i*2<=n;i++){
		printf("%d %d\n",2*i-1,2*i);
		if(2*i+1<=n)
			printf("%d %d\n",2*i-1,2*i+1);
	}
	return 0;
}
