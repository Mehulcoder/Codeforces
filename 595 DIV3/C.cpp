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

ll dp[100005];

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	//vector<int>(100005, 0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 3;
	for (int i = 4; i < 100005; ++i)
	{
		ll k = (ll)(log(i)/log(3));
		dp[i] = (ll)(pow(3, k))+(ll)dp[i-(ll)(pow(3,k))];
		//dp[i] = pow(3,(log(i)/log(3)))
	}

	cout << dp[] << '\n';

	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		cout<<dp[n];
		cout <<'\n';

	}


	return 0 ; 



}
