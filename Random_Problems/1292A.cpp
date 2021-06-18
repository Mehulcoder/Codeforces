
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
	ll n, q; cin >> n >> q;

	unordered_set<ll> s1, s2;
	ll link = 0;
	bool onGate = 0;
	bool onEnd = 0;
	ll adder = 0;
	while (q--) {
		ll a, b; cin >> a >> b;

		if (a == 1) {
			adder = (s2.find(b) != s2.end()) + (s2.find(b + 1) != s2.end()) + (s2.find(b - 1) != s2.end());
			if (s1.find(b) != s1.end()) {
				s1.erase(b);
				link -= adder;
			} else {
				s1.insert(b);
				link += adder;
			}

			if (b == 1) {
				onGate = !onGate;
			}

			if (link > 0 || onGate) {
				cout << "No" << endl;
			} else {
				cout << "Yes" << endl;
			}
		} else {
			adder = (s1.find(b) != s1.end()) + (s1.find(b + 1) != s1.end()) + (s1.find(b - 1) != s1.end());

			if (s2.find(b) != s2.end()) {
				s2.erase(b);
				link -= adder;
			} else {
				s2.insert(b);
				link += adder;
			}

			if (b == n) {
				onEnd = !onEnd;
			}

			if (link > 0 || onEnd) {
				cout << "No" << endl;
			} else {
				cout << "Yes" << endl;
			}
		}
	}

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
