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
	vll a(n);
	rep(i, n) cin >> a[i];

	vvll pre(3005, vll(n + 1, 0));
	vvll suff(3005, vll(n + 1, 0));

	rep(j, n) {
		if (j > 0) {
			rep(i, 3004) {
				pre[i][j] = pre[i][j - 1];
			}
		}
		pre[a[j]][j]++;
	}


	repr(j, n - 1) {
		if (j < n - 1) {
			rep(i, 3004) {
				suff[i][j] = suff[i][j + 1];
			}
		}
		suff[a[j]][j]++;
	}

	ll ans = 0ll;
	rep(j, n) {
		fr(k, j + 1, n - 1) {
			if (j == 0 || k == n - 1) continue;
			ans += pre[a[k]][j - 1] * suff[a[j]][k + 1];
		}
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