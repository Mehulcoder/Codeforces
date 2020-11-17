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

ll n, m;
string a, b;

vvll dp;
ll get(ll i, ll j) {
	if (i < 0 || j < 0) return 0;

	ll &anss = dp[i][j];
	if (anss != -1) return anss;

	if (a[i] == b[j]) {
		return anss = max(get(i - 1, j - 1) + 2, (ll)2);
	}

	return anss = max(get(i, j - 1), get(i - 1, j)) - 1;
}

void solve() {
	cin >> n >> m;
	cin >> a >> b;
	vset(dp, n, vll(m, -1));

	ll ans = 0ll;
	rep(i, n) {
		rep(j, m) {
			ll temp = get(i, j);
			ans = max(ans, temp);
		}
	}

	cout << ans << '\n';
	return;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll t = 1;
	while (t--) {
		solve();
	}

	return 0 ;
}