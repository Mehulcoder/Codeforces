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

const int INF = 1e9;
int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n, c;
	cin >> n >> c;
	vector<int> a(n - 1), b(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		cin >> b[i];
	}
	vector<vector<int>> dp(n, vector<int>(2, INF));
	dp[0][0] = 0, dp[0][1] = c;
	for (int i = 0; i < n - 1; ++i) {
		dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + a[i]);
		dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + a[i]);
		dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + b[i]);
		dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + b[i] + c);
	}
	
	for (int i = 0; i < n; ++i) {
		cout << min(dp[i][0], dp[i][1]) << " ";
	}
	cout << endl;
	
	return 0; 



}
