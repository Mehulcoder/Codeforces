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

void solve() {
	ll n, m; cin >> n >> m;
	vector<pll> v(m);
	vll a;
	rep(i, m) cin >> v[i].f >> v[i].s;

	rep(i, m) {
		a.push_back(v[i].f);
	}

	sort(all(a));
	vll pre(m + 1, 0);
	repr(i, m - 1) {
		pre[i] = a[i] + pre[i + 1];
	}

	ll ans = 0; ll count = 0; ll sum = 0;
	rep(i, m) {
		sum = 0;
		ll take = v[i].s;
		ll ind = upper_bound(all(a), take) - a.begin();
		count = m - ind;
		if (ind != m) sum = pre[ind];

		//I would not have had included it before, so add now
		if (v[i].f <= v[i].s) {
			sum += v[i].f;
			count++;
		}

		//In this case, I do not need the second one anymore
		//In the previous step, as I've added a value, which may not be
		// optimal now, as we are not taking it's second. So we'll replace
		//it with the most optimal first
		if (count >= n) ans = max(ans, pre[m - n]);
		else ans = max(ans, sum + (n - count) * v[i].s);
	}

	cout << ans << '\n';
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