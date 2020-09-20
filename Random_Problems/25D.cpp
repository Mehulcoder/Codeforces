/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;

#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define vset(v, n, val) v.clear(); v.resize(n, val)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)


/*
* Find the count of connected components and cycles
* Rest is pretty easy.
*/

/*
* LEETCODE sucks, change my mind!
*/

struct DSU {
	ll connected;
	vll parent, rankk;

	DSU() {}

	void init(ll n) {
		parent.clear();
		rankk.clear();
		parent.resize(n, 0);
		rankk.resize(n, 0);

		rep(i, n) {
			parent[i] = i;
			rankk[i] = 0;
		}
		connected = n;
	}

	ll findSet(ll u) {
		if (parent[u] == u) return u;
		return parent[u] = findSet(parent[u]);
	}

	bool unionSets(ll u, ll v) {
		ll a = findSet(u);
		ll b = findSet(v);
		if (a != b) {
			connected--;
			if (rankk[a] < rankk[b]) swap(a, b);
			parent[b] = a;
			if (rankk[b] == rankk[a]) rankk[a]++;
		} else {
			return 0;
		}

		return 1;
	}

	ll getRank(ll u) {
		return rankk[u];
	}
};


ll n;
vector<pll> toRemove, toAdd;
DSU dsu;
void solve() {
	cin >> n;
	toRemove.clear();
	toAdd.clear();

	dsu.init(n);

	rep(i, n - 1) {
		ll u, v; cin >> u >> v;
		u--; v--;
		if (!dsu.unionSets(u, v)) toRemove.push_back({u, v});
	}

	rep(i, n) {
		if (dsu.findSet(i) != dsu.findSet(0)) {
			dsu.unionSets(0, i);
			toAdd.push_back({0, i});
		}
	}


	cout << toAdd.size() << '\n';
	rep(i, toAdd.size()) {
		cout << toRemove[i].f + 1 << " " << toRemove[i].s + 1 << " " << toAdd[i].f + 1 << " " << toAdd[i].s + 1 << '\n';
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