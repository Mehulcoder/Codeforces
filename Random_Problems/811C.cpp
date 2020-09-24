/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>
#define vset(v, n, val) v.clear(); v.resize(n, val)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define trav(a, x) for(auto& a : x)

/*
* Beautiful question <3
* Basically dp[i]---> Best answer of the "Total array"
* if you choose only segments till i, and endpoint of the
* last segment is at i(check if that is even possible).
* Check if the rightmost element same as a[i] is at i
* and not after i, if it is after i then we cannot take make
* a segment end at i. Therefore in this case dp[i] = dp[i-1]
* else the dp[i] ---> max(dp[i-1], dp[k-1]+XOR(a[k]--->a[i]))
* where k is the extended(due to the possible 'lefter' lefts)
* left of the segment ending at i.
*/


vll a, dp;
vll leftt(5005, -1), rightt(5005, -1);
ll get(ll end) {
	if (end < 0) return 0;

	ll &ans = dp[end];
	if (ans != -1) return ans;

	if (end != rightt[a[end]]) return ans = get(end - 1);
	else {

		ll currLeft = leftt[a[end]];
		ll currRight = end;
		ll i = currRight;
		set<ll> temp;
		while (i > currLeft) {
			temp.insert(a[i]);
			if (rightt[a[i]] > currRight) return ans = get(end - 1);
			i--;
			currLeft = min(currLeft, leftt[a[i]]);
		}
		temp.insert(a[i]);
		ll val = 0;
		trav(elem, temp) {
			val = val ^ elem;
		}
		return ans = max(get(i - 1) + val, get(end - 1));
	}

}

void solve() {
	ll n; cin >> n;
	vset(a, n, 0);
	vset(dp, n, -1);

	rep(i, n) cin >> a[i];

	rep(i, n) {
		if (leftt[a[i]] == -1) {
			leftt[a[i]] = i;
			rightt[a[i]] = i;
		} else {
			rightt[a[i]] = i;
		}
	}

	rep(i, n) {
		get(i);
	}
	cout << *max_element(all(dp)) << '\n';

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