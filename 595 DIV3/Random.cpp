/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007
int m, n, k;

void dfs(int** visited, char** arr, int a, int b){
	if (a<0 || b<0 || a>=n || b>=m || visited[a][b]==1 || k<=0 || arr[a][b]!='.')
	{
		return;
	}

	visited[a][b] = 1;
	dfs(visited, arr, a+1, b);
	dfs(visited, arr, a, b+1);
	dfs(visited, arr, a-1, b);
	dfs(visited, arr, a, b-1);


	if (k>0)
	{
		arr[a][b] = 'X';
		k--;
	}

	return;


}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	
	cin>>n>>m>>k;

	char** arr = new char*[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = new char[m];
	}

	int** visited = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = new int[m];
		for (int j = 0; j < m; ++j)
		{
			visited[i][j] == 0;
		}

	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>arr[i][j];	
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (arr[i][j] == '.' && k>0)
			{
				dfs(visited, arr, i, j);
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout<<arr[i][j];
		}

		cout << '\n';
	}



	return 0 ; 



}
