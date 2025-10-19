#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,mp[100005],ans;
signed main(){
	freopen("ix.in","r",stdin);
	freopen("ix.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		ans=max(ans,++mp[x]);
	}
	cout<<ans;
	return 0;
}
