#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int b[N];
void solve()
{
	int n,r=0,a,i;
	map<int,int>m;
	cin>>n;
	m[0]=n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		if(a==1)r++;
		else r--;
		m[r]=n-i-1;
	}
	int b[N];
	for(i=0;i<n;i++)
		cin>>b[i];
	int ans=n+m[0];
	r=0;
	for(i=n-1;i>=0;i--)
	{
		if(b[i]==1)r++;
		else r--;
		if(m.find(-r)!=m.end())ans=min(ans,m[-r]+i);
	}
	cout<<ans<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)
		solve();
}