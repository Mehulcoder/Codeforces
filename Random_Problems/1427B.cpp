
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

/*
We can easily see that by filling a gap "completely" the answer increases by 2*gaplength+1
So we should try to fill shorter gaps first (2g1+2g2+2 > 2(g1+g2)+1) and the partially filled
gaps will result in increase of 2*(amountfilled)
*/


void solve() {
	ll n, k; cin >> n >> k;

	string s; cin >> s;
	ll p = -1, q = -1;

	rep(i, n) {
		if (s[i] == 'W') {
			p = i;
			break;
		}
	}

	repr(i, n - 1) {
		if (s[i] == 'W') {
			q = i;
			break;
		}
	}

	vll gaps;
	if (p == -1) {
		cout << max(2 * min(k, n) - 1, 0ll) << endl;
		return;
	}

	ll ans = 0;
	ll len = 0;
	rep(i, n) {
		if (s[i] == 'W') {
			len++;
		} else if (len != 0) {
			ans += 2 * len - 1;
			len = 0;
		}
	}

	if (len != 0) ans += 2 * len - 1;
	ll rem = p + n - 1 - q;

	bool flag = 0;
	len = 0;
	fr(i, p, q) {
		if (s[i] == 'L') {
			len++;
			flag = 1;
		}

		if (s[i] == 'W') {
			if (flag == 1) {
				gaps.push_back(len);
				len = 0;
			}
			flag = 0;
		}
	}

	sort(all(gaps));
	trav(gap, gaps) {
		if (k < gap) {
			ans += 2 * k;
			k = 0;
			break;
		} else {
			ans += 2 * gap + 1;
			k -= gap;
		}
	}

	if (k > 0) {
		ans += 2 * min(rem, k);
	}

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