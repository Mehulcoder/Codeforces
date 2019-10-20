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

bool a[10][10];
int main( int argc , char ** argv )
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
	    int x,y;
	    cin>>x>>y;
	    a[x][y]=true;
	    a[y][x]=true;
	}
	if(n<7)
		{cout<<m;return 0;}
	int d=1000;
	for(int i=1;i<7;i++)
	{
	    for(int j=i+1;j<=7;j++)
	    {
	    	int u=0;
	        for(int q=1;q<=7;q++)
	        	if(a[i][q]&&a[j][q])
	        		u++;
	    d=min(d,u);
	    }
	}
	cout<<m-d<<endl;
	    return 0;


}
