/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vll vector<long long>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)

/*
* Really nice problem:
* For each i find out the ranges for which
* it is the minimum. For the for each i
* find out the j on the left and right st
* a[i]>a[j]. Then from j+1(or j-1) to i
* the a[i] will be the minimum.

* Basically a[i] is minimum for the lengths in the
* range 1 to right[i]-left[i]-1, with center at i.
* ans[len] is valid for len--->1, 2,...,len. Choose
* maximum from right to left.
*/

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll n; cin >> n;

	vll a(n), left(n, -1), right(n, n), ans(n + 1, -1);
	rep(i, n) cin >> a[i];

	stack<ll> s;
	rep(i, n) {
		while (!s.empty() && a[s.top()] >= a[i]) s.pop();
		if (!s.empty()) left[i] = s.top();
		s.push(i);
	}

	while (!s.empty()) s.pop();

	repr(i, n - 1) {
		while (!s.empty() && a[s.top()] >= a[i]) s.pop();
		if (!s.empty()) right[i] = s.top();
		s.push(i);
	}

	rep(i, n) {
		ll len = right[i] - left[i] - 1;
		ans[len] = max(ans[len], a[i]);
	}

	frr(i, n - 1, 0) ans[i] = max(ans[i], ans[i + 1]);
	fr(i, 1, n) cout << ans[i] << ' ';
	cout << '\n';

	return 0 ;
}