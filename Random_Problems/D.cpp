
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
	ll n;
	cin >> n;

	vll a(n, 0);
	map<ll, ll> frq;

	rep(i, n) {
		cin >> a[i];
		frq[a[i]]++;
	}

	multiset<ll, greater<ll>> s;

	trav(elem, frq) {
		s.insert(elem.s);
	}


	while (s.size() >= 2) {
		auto temp1 = *s.begin();
		s.erase(s.begin());
		auto temp2 = *s.begin();
		s.erase(s.begin());

		temp1--;
		temp2--;
		if (temp1 > 0) {
			s.insert(temp1);
		}

		if (temp2 > 0) {
			s.insert(temp2);
		}
	}

	if (s.size() == 0) {
		cout << 0 << endl;
		return;
	}
	cout <<  *s.begin() << endl;
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