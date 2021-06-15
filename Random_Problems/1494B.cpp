
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
bool isOk(ll a) {
	return a >= 0 && a <= n - 2;
}

void solve() {
	ll u, r, d, l;
	cin >> n >> u >> r >> d >> l;

	rep(lu, 2) {
		rep(ru, 2) {
			rep(ld, 2) {
				rep(rd, 2) {
					ll up = lu + ru;
					ll down = ld + rd;
					ll left = lu + ld;
					ll right = ru + rd;

					ll uu = u - up;
					ll lll = l - left;
					ll rr = r - right;
					ll dd = d - down;

					if (isOk(uu) && isOk(lll) && isOk(rr) && isOk(dd)) {
						cout << "YES" << endl;
						return;
					}
				}
			}
		}
	}

	cout << "NO" << endl;
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
