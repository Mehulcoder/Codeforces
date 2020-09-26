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
const ll MOD = 1e9 + 9;


ll n, q;
vll a;
vvll dp;

ll get(ll end, bool sign) {
	if (end < 0) return 0;

	ll &ans = dp[end][sign];
	if (ans != -1) return ans;

	if (sign) {
		ans = max({a[end] + get(end - 1, 0), get(end - 1, 1)});
	} else {
		ans = max({ -a[end] + get(end - 1, 1), get(end - 1, 0)});
	}
	return ans;
}

void solve() {
	cin >> n >> q;
	a.clear();
	dp.clear();
	dp.resize(n + 2, vll(2, -1));
	a.resize(n, 0);
	rep(i, n) cin >> a[i];

	cout << max(get(n - 1, 1), get(n - 1, 0)) << '\n';
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