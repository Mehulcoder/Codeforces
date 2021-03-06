
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

ll n, p, k;
string s;
vll dp;
ll get(ll i) {
	if (i >= n) return 0;
	if (dp[i] != -1) return dp[i];
	return dp[i] = get(i + k) + '1' - s[i];
}

void solve() {
	cin >> n >> p >> k;
	p--;
	cin >> s;
	ll x, y; cin >> x >> y;

	vset(dp, n, -1);
	rep(i, n) {
		dp[i] = get(i);
	}

	ll ans = INF;
	fr(i, p, n - 1) {
		ans = min(ans, x * dp[i] + (i - p) * y);
	}

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