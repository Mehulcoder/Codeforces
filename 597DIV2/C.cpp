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
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string S;
    cin >> S;
 
    for (char c : S)
        if (c == 'w' || c == 'm') {
            cout << 0 << '\n';
            return 0;
        }
 
    int N = S.size();
    vector<int> dp(N + 1, 0);
    dp[0] = dp[1] = 1;
 
    for (int len = 2; len <= N; len++)
        if (S[len - 2] == S[len - 1] && (S[len - 1] == 'u' || S[len - 1] == 'n'))
            dp[len] = (dp[len - 1] + dp[len - 2]) % MOD;
        else
            dp[len] = dp[len - 1];
 
    cout << dp[N] << '\n';



}

