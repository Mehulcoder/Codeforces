#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	ll t = 1;
	while(t--){
		ll n; cin>>n;
		vll v(n, 0);
		map<ll, ll> m;

		rep(i, n) cin>>v[i];
		m[v[0]] = 0;

		vvll dp(2, vll(n, 0));
		dp[0][0] = 0; dp[1][0] = v[0];
		rep(i, n) dp[1][i] = v[i];

		fr(i, 1, n-1){
			dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
			if(m.find(v[i]-i)!=m.end()){
				dp[1][i] = max(dp[1][i], v[i]+dp[1][m[v[i]-i]]);
			}
			m[v[i]-i] = i;
		}
		cout << max(dp[0][n-1], dp[1][n-1]) << '\n';
	}
	
 	return 0 ; 
}



