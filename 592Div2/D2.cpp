/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
You are given a tree consisting of nn vertices. A tree is an undirected connected acyclic graph.

Example of a tree.
You have to paint each vertex into one of three colors. For each vertex, you know the cost of painting it in every color.

You have to paint the vertices so that any path consisting of exactly three distinct vertices does not contain any vertices with equal colors. In other words, let's consider all triples (x,y,z)(x,y,z) such that x≠y,y≠z,x≠zx≠y,y≠z,x≠z, xx is connected by an edge with yy, and yy is connected by an edge with zz. The colours of xx, yy and zz should be pairwise distinct. Let's call a painting which meets this condition good.

You have to calculate the minimum cost of a good painting and find one of the optimal paintings. If there is no good painting, report about it.

Input
The first line contains one integer nn (3≤n≤100000)(3≤n≤100000) — the number of vertices.

The second line contains a sequence of integers c1,1,c1,2,…,c1,nc1,1,c1,2,…,c1,n (1≤c1,i≤109)(1≤c1,i≤109), where c1,ic1,i is the cost of painting the ii-th vertex into the first color.

The third line contains a sequence of integers c2,1,c2,2,…,c2,nc2,1,c2,2,…,c2,n (1≤c2,i≤109)(1≤c2,i≤109), where c2,ic2,i is the cost of painting the ii-th vertex into the second color.

The fourth line contains a sequence of integers c3,1,c3,2,…,c3,nc3,1,c3,2,…,c3,n (1≤c3,i≤109)(1≤c3,i≤109), where c3,ic3,i is the cost of painting the ii-th vertex into the third color.

Then (n−1)(n−1) lines follow, each containing two integers ujuj and vjvj (1≤uj,vj≤n,uj≠vj)(1≤uj,vj≤n,uj≠vj) — the numbers of vertices connected by the jj-th undirected edge. It is guaranteed that these edges denote a tree.

Output
If there is no good painting, print −1−1.

Otherwise, print the minimum cost of a good painting in the first line. In the second line print nn integers b1,b2,…,bnb1,b2,…,bn (1≤bi≤3)(1≤bi≤3), where the ii-th integer should denote the color of the ii-th vertex. If there are multiple good paintings with minimum cost, print any of them.
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
	for(int i=1; i<=n; i++){
		if(adj[i].size()==1){ 
			pos[1]=i;
		}
	}

	//Make a matrix in the order of a tree
	//Last one at first and then so on

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

	//Choose initial 3 colors for last 3 terms and then find min for all possible 6 ways
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

	//Print minimum value and store the colours in fn[] and then print it
	cout<<mini<<endl;
	for(int i=1; i<=n; i++)
		fn[pos[i]]=ans[i%3]+1;

	for(int i=1; i<=n; i++) 
		cout<<fn[i]<<" ";

	cout<<endl; return 0;
}
