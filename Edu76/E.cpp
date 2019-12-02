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

int id[200005], dp[200005][4];
int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int k1, k2, k3;
	cin>>k1>>k2>>k3;

	vector<int> v1(k1,0);
	vector<int> v2(k2,0);
	vector<int> v3(k3,0);

	for (int i = 0; i < k1; ++i)
	{
		cin>>v1[i];
		id[v1[i]] = 1;
	}

	for (int i = 0; i < k2; ++i)
	{
		cin>>v2[i];
		id[v2[i]] = 2;
	}

	for (int i = 0; i < k3; ++i)
	{
		cin>>v3[i];
		id[v3[i]] = 3;
	}


	int n = k1+k2+k3;

	for(int i = 1; i <= n; ++i) {
        if(id[i] == 1) {
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + 1;
            dp[i][3] = min(dp[i - 1][1], min(dp[i - 1][2], dp[i - 1][3])) + 1;
        } else if(id[i] == 2) {
            dp[i][1] = dp[i - 1][1] + 1;
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][3] = min(dp[i - 1][1], min(dp[i - 1][2], dp[i - 1][3])) + 1;
        } else {
            dp[i][1] = dp[i - 1][1] + 1;
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + 1;
            dp[i][3] = min(dp[i - 1][1], min(dp[i - 1][2], dp[i - 1][3]));
        }
    }

    // for (int i = 1; i < 4; ++i)
    // {
    // 	for (int j = 1; j < n; ++j)
    // 	{
    // 		cout << dp[i][j] << ' ';
    // 	}
    // 	cout <<'\n';
    // }
    cout << min(dp[n][1], min(dp[n][2], dp[n][3])) << '\n';

    return 0;

}

