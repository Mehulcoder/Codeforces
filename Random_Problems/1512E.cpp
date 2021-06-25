
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
 * The main idea is, start choosing from the end, i.e choose the largest first
 * Now to check if we can choose that even, we should make sure that the remaining
 * sum should be greater than the sum of first k smallest number of the sequences
 * and should be less than or equal to the sum of first k largest, where k is the
 * remaining no. off elements to fill in the "l" to "r".
 */

bool isOk(ll diff, ll len, ll i) {
	return ((diff >= (len * (len + 1)) / 2) && (diff <= (len * (len + 2 * i - 3)) / 2));
}


void solve(ll t) {
	ll n, l, r, s;
	cin >> n >> l >> r >> s;
	l--;
	r--;

	ll len = r - l + 1;
	ll diff = s;
	vll good, bad;
	frr(i, n, 1) {
		if (len && isOk(diff - i, len - 1, i)) {
			good.push_back(i);
			diff -= i;
			len--;
		} else {
			bad.push_back(i);
		}
	}

	if (good.size() != r - l + 1) {
		cout << -1 << endl;
		return;
	}
	rep(i, n) {
		if (i >= l && i <= r) {
			cout << good.back() << " ";
			good.pop_back();
		} else {
			cout << bad.back() << " ";
			bad.pop_back();
		}
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
		solve(t);
	}

	return 0 ;
}