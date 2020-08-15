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
	ll n; cin >> n;
	vll v(n, 0);
	rep(i, n) cin >> v[i];
	ll lo = 0, hi = n - 1, ans = 0;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		bool ok = 0;
		rep(i, n - mid) {
			if (v[i] != v[i + mid]) {
				ans = max(ans, mid);
				ok = 1;
				break;
			}
		}
		if (ok || mid == 0) lo = mid + 1;
		else hi = mid - 1;
	}

	cout << ans << '\n';
	return;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
	ll t = 1;
	while (t--) {
		solve();
	}

	return 0 ;
}