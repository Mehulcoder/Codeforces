/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()
#define vll vector<long long>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

vll anss;

const ll MAXN = 300005 + 1000;
const ll MAXLOG = 20;

ll n;
ll logs[MAXN];
ll a[MAXN];
ll table[MAXLOG][MAXN];
ll table2[MAXLOG][MAXN];

void computeLogs() {
	logs[1] = 0;
	for (ll i = 2; i <= n; i++) {
		logs[i] = logs[i / 2] + 1;
	}
}



void buildSparseTable() {
	for (ll i = 0; i < n; i++) table2[0][i] = a[i], table[0][i] = a[i];

	for (ll j = 1; j <= logs[n]; j++) {
		ll currLen = (1 << j);
		for (ll i = 0; i <= n - currLen; i++) {
			table2[j][i] = __gcd(table2[j - 1][i],
			                     table2[j - 1][i + (1 << (j - 1))]);
			table[j][i] = min(table[j - 1][i],
			                  table[j - 1][i + (1 << (j - 1))]);
		}
	}
}


ll getMin(ll l, ll r) {
	ll p = logs[r - l + 1];
	ll pLen = 1 << p; // 2^p
	return min(table[p][l], table[p][r - pLen + 1]);
}

ll getGcd(ll l, ll r) {
	ll p = logs[r - l + 1];
	ll pLen = 1 << p; // 2^p
	return __gcd(table2[p][l], table2[p][r - pLen + 1]);
}

bool check(ll len) {
	bool ok = 0;
	rep(l, n) {
		ll r = l + len - 1;
		if (r >= n) break;
		ll g = getGcd(l, r);
		if (g == getMin(l, r)) ok = 1;
		if (ok) return 1;
	}

	return ok;
}

void gett(ll len) {
	rep(l, n) {
		bool ok = 0;
		ll r = l + len - 1;
		if (r >= n) break;
		ll g = getGcd(l, r);
		if (g == getMin(l, r)) ok = 1;
		if (ok) anss.push_back(l);
	}

	return;
}

void solve() {
	cin >> n;
	rep(i, n) cin >> a[i];
	anss.clear();

	computeLogs();
	buildSparseTable();


	ll lo = 1;
	ll hi = n;
	ll ans = 1;

	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (check(mid)) {
			lo = mid + 1;
			ans = max(ans, mid);
		} else {
			hi = mid - 1;
		}
	}

	gett(ans);

	sort(all(anss));
	cout << anss.size() << " " << ans - 1 << '\n';
	rep(i, anss.size()) {
		cout << anss[i] + 1 << ' ';
	}
	cout << '\n';

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