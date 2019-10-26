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
	
	int t;
	cin>>t;

	while(t--){
		int n, k, d;
		cin>>n>>k>>d;

		vector<int> channels(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin>>channels[i];
		}

		int ans = INT_MAX;

		int start = 0;

		while(start<=n-d){
			int temp = 0;
			set<int> myset;
			for (int i = 0; i < d; ++i)
			{
				if (myset.find(channels[start+i])==myset.end())
				{
					myset.insert(channels[start+i]);
					temp++;
				}
			}
			
			start++;
			ans = min(temp, ans);
		}

		cout << ans << '\n';

	}


	return 0 ; 



}
