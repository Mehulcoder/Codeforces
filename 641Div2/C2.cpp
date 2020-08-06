#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,x,g,l,ans=0;
	cin>>n>>x;
	g=x;
	for(int i=1;i<n;i++)
	{
		cin>>x;
		l=(g*x)/__gcd(g,x);
		ans=__gcd(ans,l);
		g=__gcd(g,x);
	}
	cout<<ans<<endl;
	return 0;
}