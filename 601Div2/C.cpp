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

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
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

	vector<set<int>> v1(n-2);
	vector<set<int>> v1(n);
	for (int i = 0; i < n-2; ++i)
	{
		int a, b, c;
		cin>>a>>b>>c;

		v1[i].insert(a-1);
		v1[i].insert(b-1);
		v1[i].insert(c-1);

		v2[a-1].insert(i);
		v2[b-1].insert(i);
		v2[c-1].insert(i);
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

	int temp = *(ans[0].begin());


	



	return 0 ; 



}

