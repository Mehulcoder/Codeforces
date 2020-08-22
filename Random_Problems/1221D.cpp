/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define vset(v, n, val) v.clear(); v.resize(n, val)
#define INF 4557430888798830399ll
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

/*
* CATCH:
* You can increase the height of any block by at max 2
* in the case of most optimal answer. Prove by contradiction
*/
vll a, b, newH;
vvll dp;
ll n;
ll get(ll end, ll times) {
	if (end == 0) return b[end] * times;

	ll &ans = dp[times][end];
	if (ans != -1) return ans;

	ll temp0 = get(end - 1, 0);
	ll temp1 = get(end - 1, 1);
	ll temp2 = get(end - 1, 2);

	ll newHeight = a[end] + times;
	ll cost = b[end] * times;

	if (newHeight == a[end - 1] + 0) temp0 = INF;
	if (newHeight == a[end - 1] + 1) temp1 = INF;
	if (newHeight == a[end - 1] + 2) temp2 = INF;

	return ans = cost + min({temp0, temp1, temp2});
}

void solve() {
	cin >> n;
	vset(a, n, 0);
	vset(b, n, 0);
	vset(newH, n, -1);
	vset(dp, 3, vll(n, -1));

	rep(i, n) {
		cin >> a[i] >> b[i];
	}

	cout << min({get(n - 1, 0), get(n - 1, 1), get(n - 1, 2)}) << '\n';
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