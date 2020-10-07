/*
Author: Mehul Chaturvedi
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>
#define vset(v, n, val) v.clear(); v.resize(n, val)
#define INF 4557430888798830399ll
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define trav(a, x) for(auto& a : x)

ll n, m;
vll a, b, suffa, prefb, vals;

ll get(ll changeTo) {
	ll ans = 0;

	ll inda = upper_bound(all(a), changeTo) - a.begin();
	ll counta = n - inda;
	if (inda <= n - 1) {
		ans += (abs(counta * changeTo - suffa[inda]));
	}

	ll indb = lower_bound(all(b), changeTo) - b.begin() - 1;
	ll countb = indb + 1;
	if (indb >= 0) {
		ans += abs(prefb[indb] - countb * changeTo);
	}

	return ans;
}

void solve() {
	cin >> n;
	vset(a, n, 0);
	rep(i, n) cin >> a[i];

	cin >> m;
	vset(b, m, 0);
	rep(i, m) cin >> b[i];

	sort(all(a));
	sort(all(b));

	rep(i, n) vals.push_back(a[i]);
	rep(i, m) vals.push_back(b[i]);

	sort(all(vals));

	vset(suffa, n, 0);
	vset(prefb, m, 0);

	repr(i, n - 1) {
		suffa[i] = a[i];
		if (i != n - 1) suffa[i] += suffa[i + 1];
	}


	rep(i, m) {
		prefb[i] = b[i];
		if (i != 0) prefb[i] += prefb[i - 1];
	}


	ll ans = INF;
	trav(elem, vals) {
		ll cost = get(elem);
		ans = min(ans, cost);
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