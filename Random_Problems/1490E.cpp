
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

ll n;
vector<pll> a;

bool ok(ll i) {
	ll curr = 0;
	fr(j, 0, i) {
		curr += a[j].f;
	}

	fr(j, i + 1, n - 1) {
		if (curr < a[j].f) return 0;
		curr += a[j].f;
	}

	return 1;
}

void solve() {
	cin >> n;
	a.clear();
	a.resize(n);

	rep(i, n) {
		cin >> a[i].f;
		a[i].s = i;
	}

	ll lo = 0;
	ll hi = n - 1;

	sort(all(a));
	ll ind = -1;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (ok(mid)) hi = mid - 1, ind = mid;
		else lo = mid + 1;
	}

	vll ans;
	fr(i, ind, n - 1) {
		ans.push_back(a[i].s);
	}


	sort(all(ans));
	cout << ans.size() << endl;
	trav(elem, ans) {
		cout << elem + 1 << " ";
	}

	cout << endl;
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
