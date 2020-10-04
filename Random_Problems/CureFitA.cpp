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


vvll times;
vll dp;
ll n;
bool mySort(vll &a, vll &b) {
	return (a[0] < b[0]);
}

ll getInd(ll minStart, ll indStart) {
	ll lo = indStart;
	ll hi = n - 1;

	ll ans = -1;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (times[mid][0] >= minStart) {
			hi = mid - 1;
			ans = mid;
		} else {
			lo = mid + 1;
		}
	}

	return ans;
}

ll get(ll startInd) {
	if (startInd == n) return 0;

	ll &anss = dp[startInd];
	if (anss != -1) return anss;

	ll ans = times[startInd][2];
	ll ending = times[startInd][1];
	ll ind2 = getInd(ending, startInd + 1);

	if (ind2 != -1) {
		ans += get(ind2);
	}


	ll ans2 = get(startInd + 1);
	return anss = max(ans, ans2);
}

void solve() {
	cin >> n;
	vset(times, n, vll(3, -1));
	vset(dp, n + 10, -1);

	rep(i, n) cin >> times[i][0];
	rep(i, n) cin >> times[i][1];
	rep(i, n) cin >> times[i][2];

	sort(all(times), mySort);

	ll ans = get(0);

	cout << ans << '\n';
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