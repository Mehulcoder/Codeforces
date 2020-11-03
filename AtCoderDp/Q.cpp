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
const ll N = 2e5 + 10;

class node {
public:
	ll ind;
	ll val;

	node(ll indd, ll vall) {
		ind = indd;
		val = vall;
	}

};

ll n;
ll h[N];
ll a[N];
ll dp[N];

vector<node> t;

node help(node left, node right) {
	if (left.val > right.val) return left;
	else return right;
}

node gett(ll start, ll tl, ll tr, ll l, ll r) {
	if (tl >= r || tr <= l) {
		return node(-1, -1);
	}

	if (l <= tl && r >= tr) {
		return t[start];
	}

	ll mid = (tl + tr) / 2;
	node left = gett(2 * start + 1, tl, mid, l, r);
	node right = gett(2 * start + 2, mid, tr, l, r);
	node ans = help(left, right);
	return ans;
}

void sett(ll start, ll tl, ll tr, ll pos, ll val, ll index) {
	if (tl + 1 == tr) {
		t[start] = node(index, val);
		return;
	}
	ll mid = (tl + tr) / 2;
	if (pos < mid) {
		sett(2 * start + 1, tl, mid, pos, val, index);
	} else {
		sett(2 * start + 2, mid, tr, pos, val, index);
	}
	node left = t[2 * start + 1];
	node right = t[2 * start + 2];
	t[start] = help(left, right);
	return;
}


void solve() {
	cin >> n;
	rep(i, n) cin >> h[i];
	rep(i, n) cin >> a[i];

	fil(dp, -1);
	t.resize(4 * n, node(-1, -1));

	ll ans = 0;
	rep(i, n) {
		ll indd = gett(0, 0, n, 0, h[i]).ind;
		dp[i] = a[i];
		if (indd != -1) dp[i] += dp[indd];
		sett(0, 0, n, h[i], dp[i], i);
		ans = max(ans, dp[i]);
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