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


ll ceel(ll a, ll b) {
	if (a % b == 0) return a / b;
	else return a / b + 1;
}

void solve() {
	ll n, w;
	cin >> n >> w;

	vector<pll> a(n), arr;
	rep(i, n) {
		ll t; cin >> t;
		a[i] = {t, i};
	}

	sort(all(a));
	rep(i, n) {
		if (a[i].first <= w) arr.push_back(a[i]);
	}

	ll sum = 0;
	n = arr.size();
	vll ans;
	repr(i, n - 1) {
		if (sum + arr[i].first <= w)sum += arr[i].first, ans.push_back(arr[i].second + 1);
	}

	ll anss = sum >= ceel(w, 2) && sum <= w;
	if (anss == 0) {
		cout << -1 << '\n';
		return;
	}

	sort(all(ans));
	cout << ans.size() << '\n';
	rep(i, ans.size()) {
		cout << ans[i] << ' ';
	}

	cout << '\n';

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