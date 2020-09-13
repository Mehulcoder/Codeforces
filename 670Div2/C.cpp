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

ll n;
vvll edges;
vector<ll> Centroid(const vector<vector<ll>> &g) {
	ll n = g.size();
	vector<ll> centroid;
	vector<ll> sz(n);

	function<void (ll, ll)> dfs = [&](ll u, ll prev) {
		sz[u] = 1;
		bool is_centroid = true;
		for (auto v : g[u]) if (v != prev) {
				dfs(v, u);
				sz[u] += sz[v];
				if (sz[v] > n / 2) is_centroid = false;
			}
		if (n - sz[u] > n / 2) is_centroid = false;
		if (is_centroid) centroid.push_back(u);
	};
	dfs(0, -1);
	return centroid;
}


void solve() {
	cin >> n;
	vset(edges, n, vll(0));

	pll buffer = { -1, -1};
	rep(i, n - 1) {
		ll x, y; cin >> x >> y;
		x--; y--;
		edges[x].push_back(y);
		edges[y].push_back(x);

		if (buffer.f == -1)
			buffer =  {x, y};
	}


	vector<ll> ans = Centroid(edges);
	if (ans.size() == 1) {
		cout << buffer.f + 1 << " " << buffer.s + 1 << '\n';
		cout << buffer.f + 1 << " " << buffer.s + 1 << '\n';
	} else {
		ll c1 = ans[0];
		ll c2 = ans[1];

		ll cc = -1;
		trav(child, edges[c1]) {
			if (child != c2) {
				cc = child;
				break;
			}
		}

		cout << c1 + 1 << " " << cc + 1 << '\n';
		cout << c2 + 1 << " " << cc + 1 << '\n';
	}
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