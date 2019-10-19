/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT

*/

#include<bits/stdc++.h>
using namespace std;
int n, pos[100069]; long long cost[4][100069];
vector<int>adj[100069];
int p[3]={0, 1, 2}, ans[3];
int fn[100069];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n;
	for(int i=1; i<4; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin>>cost[i][j];
		}
	}
	for(int i=0; i<n-1; i++)
	{
		int u, v; cin>>u>>v;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	for(int i=1; i<=n; i++) 
		if(adj[i].size()==1) 
			pos[1]=i;
	for(int i=1; i<n; i++){

		if(adj[pos[i]].size()>2)
			{
				cout<<-1<<endl; return 0;
			}
		if(adj[pos[i]][0]!=pos[i-1]) 
			pos[i+1]=adj[pos[i]][0];
		else 
			pos[i+1]=adj[pos[i]][1];
	}

	long long mini=1e18+69;
	
	do{
		long long nw=0;
		for(int i=1; i<=n; i++) 
			nw+=cost[p[i%3]+1][pos[i]];
		if(nw<mini)
		{
			mini=nw; 
			memcpy(ans, p, sizeof(p));
		}
	}while(next_permutation(p, p+3));

	
	cout<<mini<<endl;
	for(int i=1; i<=n; i++)
		fn[pos[i]]=ans[i%3]+1;
	
	for(int i=1; i<=n; i++) 
		cout<<fn[i]<<" ";

	cout<<endl; return 0;
}
