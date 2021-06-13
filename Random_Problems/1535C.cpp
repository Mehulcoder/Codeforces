
/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

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
const ll MOD = 1e9 + 7;

void solve() {
	string s; cin >> s;
	ll n = s.size();


	vvll dp(n, vll(2, 0));
	if (s[0] == '0') {
		dp[0][0] = 1;
	} else if (s[0] == '1') {
		dp[0][1] = 1;
	} else {
		dp[0][0] = 1;
		dp[0][1] = 1;
	}

	fr(i, 1, n - 1) {
		if (s[i] == '0') {
			dp[i][0] = 1 + dp[i - 1][1];
		} else if (s[i] == '1') {
			dp[i][1] = 1 + dp[i - 1][0];
		} else {
			dp[i][0] = 1 + dp[i - 1][1];
			dp[i][1] = 1 + dp[i - 1][0];
		}
	}

	ll ans = 0;
	rep(i, n) {
		if (s[i] != '?') {
			ans += dp[i][s[i] - '0'];
		} else {
			ans += max(dp[i][0], dp[i][1]);
		}
	}

	hello world << cout

	            cout << ans << endl;
	return;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0 ;
}