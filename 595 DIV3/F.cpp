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
	
	int n, k;
	cin>>n>>k;

	vector<int> weight(n, 0);
	vector<int>* edges = new vector<int>[n-1];

	for (int i = 0; i < n-1; ++i)
	{
		int a, b;
		cin>>a>>b;
		edges[a-1].push_back(b-1);
		edges[b-1].push_back(a-1);
	}

	cout << go(0, weight, edges, n, k) << '\n';



	return 0 ; 



}
