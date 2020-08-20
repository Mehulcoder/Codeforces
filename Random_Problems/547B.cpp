/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;

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
const ll MOD = 1e9 + 9;


void solve() {
	ll n; cin >> n;

	vll a(n), left(n, -1), right(n, n), ans(n + 1, -1);
	rep(i, n) cin >> a[i];

	stack<ll> s;
	rep(i, n) {
		while (!s.empty() && a[s.top()] >= a[i]) s.pop();
		if (!s.empty() && a[s.top()] < a[i]) left[i] = s.top();
		s.push(i);
	}

	repr(i, n - 1) {
		while (!s.empty() && a[s.top()] >= a[i]) s.pop();
		if (!s.empty() && a[s.top()] < a[i]) right[i] = s.top();
		s.push(i);
	}

	rep(i, n) {
		//Stack has the index which has value greater
		ll len = right[i] - left[i] - 1;
		ans[len] = max(ans[len], a[i]);
	}
	frr(i, n - 1, 0)ans[i] = max(ans[i], ans[i + 1]);
	fr(i, 1, n) cout << ans[i] << ' ';
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