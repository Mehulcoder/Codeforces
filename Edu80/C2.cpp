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

int dp[1002][1002] = {};

int go(int l, int value){
	if (l==1)
	{
		return 1;
	}

	if (dp[l][value]!=-1)
	{
		return dp[l][value]%MOD;
	}

	int small = 0;
	for (int i = 1; i <= value; ++i)
	{
		small+=go(l-1, i)%MOD;
		small = small%MOD;
	}

	dp[l][value] = small%MOD;
	return small%MOD;
}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n, m;
	cin>>n>>m;

	memset(dp, -1, sizeof(dp));

	// cout << dp[1000][1000] << '\n';

	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans+=go(2*m, i)%MOD;
		ans = ans%MOD;
	}

	cout << ans%MOD << '\n';



	return 0 ; 



}

