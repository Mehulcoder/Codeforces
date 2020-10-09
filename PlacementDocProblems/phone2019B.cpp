/*
Author: Mehul Chaturvedi
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define vll vector<long long>
#define vset(v, n, val) v.clear(); v.resize(n, val)
#define INF 4557430888798830399ll
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)


/*
* Say we remove the num at index k.
* The maximum sum, so that it lies within the current subarray
* will be rMax[i] (maxPrefixSum on it's right) - lMin[j-1]
* (minimum prefix sum on it's left) - a[k]

* Check the edge case when there are no negative numbers
*/

ll n;
vll a;
void solve() {
	cin >> n;
	vset(a, n, 0);

	rep(i, n) cin >> a[i];
	vll pre(n, 0);

	rep(i, n) {
		if (i != 0)
			pre[i] = pre[i - 1] + a[i];
		else
			pre[i] = a[i];
	}

	vll lMin(n, 0);
	vll rMax(n, 0);

	lMin[0] = 0;
	rep(i, n) {
		if (i != 0) lMin[i] = min(lMin[i - 1], pre[i - 1]);
	}

	ll ans = -INF;
	rep(i, n) ans = max(ans, pre[i] - lMin[i]);

	rMax[n - 1] = pre[n - 1];
	repr(i, n - 2) rMax[i] = max(rMax[i + 1], pre[i]);


	rep(i, n) {
		if (a[i] < 0) {
			ans = max(ans, rMax[i] - lMin[i] - a[i]);
		}
	}

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