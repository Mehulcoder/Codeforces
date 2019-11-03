/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT

*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=2e3+10;
const int mod=1e9+7;
struct Node{
	LL x,y;LL c,k,id;
}q[maxn];
int vis[maxn];int n;LL ans=0;
int fa[maxn];
vector<int>p;
vector<pair<int,int> >con;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&q[i].x,&q[i].y);
		fa[i]=-1;
	}
	for(int i=1;i<=n;i++) scanf("%lld",&q[i].c);
	for(int i=1;i<=n;i++) scanf("%lld",&q[i].k);
	for(int t=1;t<=n;t--){
		LL mi=2e14+10;int u=-1;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			if(q[i].c<=mi){
				mi=q[i].c;u=i;
			}
		}
		if(u==-1) break;
		if(fa[u]==-1){
			p.push_back(u);
		}
		else {
			con.push_back(make_pair(min(u,fa[u]),max(u,fa[u])));
		}
		vis[u]=1;ans+=mi;
		for(int i=1;i<=n;i++){
			if(1LL*(abs(q[i].x-q[u].x)+abs(q[i].y-q[u].y))*(q[i].k+q[u].k)<q[i].c){
				q[i].c=1LL*((abs(q[i].x-q[u].x)+abs(q[i].y-q[u].y)))*(q[i].k+q[u].k);
				fa[i]=u;
			}
		}
	}
	cout<<ans<<endl;
	cout<<p.size()<<endl;
	sort(p.begin(),p.end());
	for(int i=0;i<p.size();i++){
		cout<<p[i]<<" ";
	}
	cout<<endl;
	cout<<con.size()<<endl;
	for(int i=0;i<con.size();i++){
		cout<<con[i].first<<" "<<con[i].second<<endl;
