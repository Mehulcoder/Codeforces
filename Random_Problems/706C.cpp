#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<long long>
#define repr(i, n) for (int i = n; i >= 0; i--)
#define vvll vector<vector<ll>>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define INF 4557430888798830399ll
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	ll n; cin>>n;
	
	vll energy(n);
	vvll dp(2, vll(n, 0));
	rep(i, n) cin>>energy[i];

	vector<string> v(n);
	rep(i, n) cin>>v[i];

	dp[0][0] = 0, dp[1][0] = energy[0];
	fr(i, 1, n-1){
		string s0 = v[i-1], s1 = v[i], rev0=s0, rev1=s1;
		dp[1][i] = energy[i];
		ll add = INF;

		reverse(all(rev0));
		reverse(all(rev1));

		//Not reverse the current one
		if(lexicographical_compare(all(s0), allr(s1)) || s0==rev1) add = min(add, dp[0][i-1]);
		if(lexicographical_compare(allr(s0), allr(s1)) || rev0==rev1) add = min(add, dp[1][i-1]);
		dp[1][i]+=add;

		//Reverse the current one
		add = INF;
		if(lexicographical_compare(all(s0), all(s1)) || s0==s1) add = min(add, dp[0][i-1]);
		if(lexicographical_compare(allr(s0), all(s1)) || rev0==s1) add = min(add, dp[1][i-1]);
		dp[0][i]+=add;
	}
	ll ans = min(dp[1][n-1], dp[0][n-1]);
	cout << (ans==INF?-1:ans) << '\n';
 	
 	return 0 ; 
}

