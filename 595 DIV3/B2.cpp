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
	
	int q;
	cin>>q;

	while(q--){
		int n;
		cin>>n;
		vector<int> arr(n+1, 0);
		for (int i = 1; i < n+1; ++i)
		{
			cin>>arr[i];
		}

		vector<int> dp(n+1, -1);
		for (int i = 1; i < n+1; ++i)
		{
			if (arr[i] == i)
			{
				dp[i] = 1;
			}

			int j=i;
			int day = 0;
			while(arr[j]>i){
				j = arr[j];
				day++;
			}

			if (arr[j]==i)
			{
				day++;
				dp[i] = day;
			}else{
				dp[i] = dp[arr[j]];
			}

			cout<<dp[i]<<" ";
		}

		cout << '\n';

		
	}



	return 0 ; 



}
