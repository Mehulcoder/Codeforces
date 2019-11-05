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


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n, m, d;
	cin>>n>>m>>d;

	vector<int> wood(m, 0);
	int pos = 0;
	int sum = 0;
	for (int i = 0; i < m; ++i)
	{
		cin>>wood[i];
		pos = pos+d+wood[i]-1;
		sum+= wood[i];
	}
	if (pos+d<n+1)
	{
		cout << "NO" << '\n';
		return 0;
	}

	cout << "YES" << '\n';

	pos = 0;
	unordered_map<int, int> blocks;


	int i = 0;
	// cout << sum << '\n';
	// return 0;
	while(1){
		pos = pos+d;
		if (pos+sum-1>n)
		{
			pos = pos-d;
			pos = n-sum+1;
		}

		if (pos>=n+1)
		{
			break;
		}
		
		for (int j = 0; j < wood[i]; ++j)
		{
			blocks[pos+j] = i+1;	
		}
		pos = pos+wood[i]-1;
		sum-=wood[i];	
		i++;
	}

	vector<int>(n+1, 0);
	for (int k = 1; k < n+1; ++k)
	{
		cout << blocks[k] << ' ';
	}
	cout <<  '\n';
	



	return 0 ; 



}

