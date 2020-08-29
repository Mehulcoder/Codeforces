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
	ll p1, p2, cs, cw, s, w;
	cin >> p1 >> p2 >> cs >> cw >> s >> w;
	if (s > w) {
		swap(cs, cw);
		swap(s, w);
	}
	ll ans = 0;
	for (ll s1 = 0; s1 <= cs && s1 * s <= p1; s1++) {
		ll sr = cs - s1;
		ll w1 = min(cw, (p1 - s1 * s) / w);
		ll wr = cw - w1;
		ll s2 = min(sr, p2 / s);
		ll w2 = min(wr, (p2 - s2 * s) / w);
		ans = max(ans, s1 + w1 + s2 + w2);
	}
	cout << ans << endl;

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