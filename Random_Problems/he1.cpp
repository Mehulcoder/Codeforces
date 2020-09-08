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


ll n, q;
vector<vector<ll>> edges2;
vll par;
void get(ll root, ll target, ll parent) {
	if (root == target) return;
	rep(child, n) {
		if (child == parent) continue;
		if (edges2[child][root] != -1) {
			par[child] = root;
			get(child, target, root);
		}
	}

	return;
}

void solve() {
	cin >> n;
	edges2.resize(n, vector<ll>(n, -1));

	par.resize(n, -1);
	rep(i, n - 1) {
		ll u, v, w;
		cin >> u >> v >> w;
		u--; v--;

		edges2[u][v] = w;
		edges2[v][u] = w;
	}

	cin >> q;
	rep(i, q) {
		ll u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		get(u, v, -1);
		ll maxi = -INF;
		ll curr = v;
		while (curr != u) {
			ll prev = par[curr];
			maxi = max(maxi, edges2[curr][prev]);
			curr = prev;
		}
		if (w < maxi) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

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