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

/**
 * If you have sufficient k, one should be the answer
 * If not, try to put first k elements in an array (rest all same)
 * Now try to put elements in group of k-1 or less in each of the
 * other arrays.
 */


ll ceel(ll a, ll b) {
	ll ans;
	if (a % b == 0) {
		ans =  a / b;
	} else {
		ans = a / b + 1;
	}

	return ans;
}

void solve() {
	ll n, k; cin >> n >> k;

	vll a(n);

	rep(i, n) cin >> a[i];

	set<ll> s;
	rep(i, n) {
		s.insert(a[i]);
	}

	n = s.size();
	if (n == 1 || n <= k) {
		cout << 1 << '\n';
		return;
	}
	if (k == 1) {
		cout << -1 << '\n';
		return;
	}

	cout << max(1ll, 1 + ceel(n - k, k - 1)) << '\n';
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