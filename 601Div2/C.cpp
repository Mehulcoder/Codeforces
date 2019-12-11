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

#define debug(x) cout << '>' << #x << ':' << x << endl;
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
	
	int n;
	cin>>n;

	vector<vector<int>> v1(n-2);
	vector<vector<int>> v2(n);
	for (int i = 0; i < n-2; ++i)
	{
		int a, b, c;
		cin>>a>>b>>c;

		v1[i].push_back(a-1);
		v1[i].push_back(b-1);
		v1[i].push_back(c-1);

		v2[a-1].push_back(i);
		v2[b-1].push_back(i);
		v2[c-1].push_back(i);
	}

	vector<int> freq(n, 0);

	for (int i = 0; i < n; ++i)
	{
		freq[i] = v2[i].size();
	}

	vector<int> ends;
	for (int i = 0; i < n; ++i)
	{
		if (freq[i]==1)
		{
			ends.push_back(i);
		}
	}

	vector<int> ans(n, 0);

	ans[0] = ends[0];
	ans[n-1] = ends[1];
	// debug(ans[n-1])

	int temp = (v2[ans[0]][0]);
	// debug(temp)
	// debug(ans[0])

	for(auto num : v1[temp]){
		if (v2[num].size() == 2)
		{
			ans[1] = num;
			break;
		}
	}

	// debug(ans[1])
	unordered_map<int, int> m1;
	for (int i = 0; i < n-3; ++i)
	{
		int a,b;
		a = ans[i];
		b = ans[i+1];

		// debug(a);
		// debug(b)
		int common;
		for (int j = 0; j < v2[a].size(); ++j)
		{
			int c1 = v2[a][j];
			for (int k = 0; k < v2[b].size(); ++k)
			{
				if (v2[b][k]==c1 && m1[c1]==0)
				{
					common = c1;
					break;
				}	
			}
		}
		m1[common]++;
		// debug(common)
		// debug(m1[common])

		// debug(v1[common][2])

		for (int j = 0; j < v1[common].size(); ++j)
		{
			if (v1[common][j]!=a && v1[common][j]!=b)
			{
				// debug(a)
				// debug(b)
				ans[i+2] = v1[common][j];
				// debug(i);
				// debug(ans[i+2])
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << ans[i]+1 << ' ';
	}
	cout <<'\n';


	



	return 0 ; 



}

