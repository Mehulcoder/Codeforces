/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define vll vector<long long>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define trav(a, x) for(auto& a : x)



/*
Think of it as, you have say k intervals(imagine as segments on x axis)
and you have placed them one after other in the increasing order of their end.
Now you basically need to find the total number of vertical lines to make, so
that every segment is cut atleast once.
*/

bool mySort(pll a, pll b) {
	return a.s < b.s;
}

void solve() {
	ll n; cin >> n;
	vll a(n, 0);
	rep(i, n) cin >> a[i];

	vector<pll> intervals;
	vll pre(n, 0);
	rep(i, n) {
		pre[i] = a[i];
		if (i != 0) {
			pre[i] += pre[i - 1];
		}
	}

	map<ll, ll> m;
	m[0] = -1;
	rep(i, n) {
		if (m.find(pre[i]) != m.end()) {
			intervals.push_back({m[pre[i]] + 1, i});
		}
		m[pre[i]] = i;
	}

	sort(all(intervals), mySort);
	if (!intervals.size()) {
		cout << 0 << '\n';
		return;
	}

	ll ans = 1;
	pll prev = intervals[0];
	fr(i, 1, intervals.size() - 1) {
		pll curr = intervals[i];
		if (prev.s > curr.f) continue;
		else {
			prev = curr;
			ans++;
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