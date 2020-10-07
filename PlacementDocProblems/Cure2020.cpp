/*
Author: Mehul Chaturvedi
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>
#define INF 4557430888798830399ll
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
/*
What could be the worst case? That the maximum time in the array is our ans.
What could be the best? 0 days.Now, say if you are given a day, and I ask you that could this be the answer?
Simple O(n), just check if >=c groups can be formed of length m. If yes then, hi=mid-1 (and update ans) else
lo=mid+1
*/
void solve() {
	ll n, c, m; cin >> n >> c >> m;

	vll v(n, 0);
	rep(i, n) cin >> v[i];

	ll hi = *max_element(all(v));
	ll lo = 0;

	ll ans = INF;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		vll temp(n, 0);
		rep(i, n) temp[i] = (v[i] <= mid);
		ll count = 0;
		ll blocks = 0;
		rep(i, n) {
			if (temp[i] == 0 && count != 0) {
				blocks += count / m;
				count = 0;
			} else if (temp[i] != 0) {
				count++;
			}
		}
		blocks += count / m;

		if (blocks >= c) {
			ans = min(ans, mid);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout << ((ans == INF) ? (-1) : (ans)) << '\n';

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