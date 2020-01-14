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

int dp[12][1005][1005] = {0};

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n,m;
	cin>>n>>m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = n; j >= i; --j)
		{
			// cout << "i "<<i<<" j "<<j << '\n';
			dp[1][i][j] = 1;
		}
	}

	

	for (int i = 2; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = n; k >= j; --k)
			{
				if (1)
				{
					// cout << "yo "<<i-1<<j<<k << '\n';
					for (int p = j; p <= k; ++p)
					{
						for (int q = min(k, p); q >= p ; --q)
						{
							// if (p==1 && q==1)
							// {
							// 	cout << "here" << '\n';
							// 	cout << j<<" "<<k << '\n';
							// }
							dp[i][p][q] += ((k-p+1)%MOD);
							dp[i][p][q] = dp[i][p][q]%MOD;

						}
					}
				}
			}
		}
	}

	// for (int i = 1; i <= n; ++i)
	// {
	// 	for (int j = 1; j <= n; ++j)
	// 	{
	// 		debug(i)
	// 		debug(j)
	// 		debug(dp[2][i][j]);
	// 	}
	// }

	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = n; j >= i; --j)
		{
			ans += dp[m][i][j]%MOD;
		}
	}

	

	cout << ans%MOD << endl;

	// cout << dp[1][1][99] << '\n';
	



	return 0 ; 



}

