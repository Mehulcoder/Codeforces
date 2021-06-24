
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
 * I followed a very simple greedy approach, first match
 * the left with right (i.e. remove the ones that are already
 * matched) , also make sure that the left one is the one
 * with smaller size.
 * Now while the size of right is more than that of left
 * keep on moving the numbers with more than one count
 * to the left.
 * In the end all you can do is change the color of the
 * right ones and move the extra ones to the left, by changing
 * their color.
 */

void solve() {
	ll n, l, r; cin >> n >> l >> r;

	vll left(l, 0), right(r, 0);
	rep(i, l) cin >> left[i];
	rep(i, r) cin >> right[i];

	unordered_multiset<ll> a, b;
	trav(elem, left) a.insert(elem);
	trav(elem, right) b.insert(elem);

	if (a.size() > b.size()) swap(a, b);


	unordered_multiset<ll> aa;
	trav(elem, a) {
		if (b.find(elem) != b.end()) {
			b.erase(b.find(elem));
		} else {
			aa.insert(elem);
		}
	}

	unordered_map<ll, ll> m;
	trav(elem, b) m[elem]++;
	ll diff = b.size() - aa.size();
	ll ans = 0;
	trav(elem, m) {
		while (diff && elem.s > 1) {
			elem.s -= 2;
			diff -= 2;
			ans++;
		}
	}

	ans += aa.size() + diff;
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