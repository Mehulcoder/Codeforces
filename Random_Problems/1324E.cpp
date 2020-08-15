/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define vset(v, n, val) v.clear(); v.resize(n, val)
#define INF 4557430888798830399ll
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define trav(a, x) for(auto& a : x)
#define fil(ar, val) memset(ar, val, sizeof(ar))
const ll MOD = 1e9 + 9;

bool in(ll x, ll l, ll r) {
	return l <= x && x <= r;
}
/*
* To get the answer for till ith pos you must know
* that how much backs you've taken till now, and what
* is the answer for that much amount of backs.
* Therefore dp[i][j] will store the ans for, the curr pos
* and number of backs taken till now.
*/
int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll n, h, l, r;
	cin >> n >> h >> l >> r;

	vll a(n);
	for (auto &it : a) cin >> it;

	vvll dp(n + 1, vll(n + 1, INT_MIN));
	dp[0][0] = 0;
	ll sum = 0;

	rep(i, n) {
		sum += a[i];
		rep(j, n + 1) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + in((sum - j) % h, l, r));
			if (j < n) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + in((sum - j - 1) % h, l, r));
		}
	}

	cout << *max_element(all(dp[n])) << endl;

	return 0 ;
}

