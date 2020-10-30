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

ll n;
vll a;

// For every l to r I should be able to return the
// Minimum element whose last[] is < k


//That element is represtented by tree index
//Value inside tree represents last index of i
//t[i] ---> Last index of i ----> need to get it < k
//tl ----> value ---> need to get min of this
ll get(ll start, ll tl, ll tr, ll k) {
	if (tl + 1 == tr) return tl;

	ll tm = (tl + tr) / 2;
	if (t[2 * start + 1] < k) {
		return get(2 * start + 1, tl, tm, k);
	}

	return get(2 * start + 2, tm, tr, k);
}

void solve() {
	cin >> n;
	a.resize(n, 0);

	rep(i, n) cin >> a[i];

	map<ll, ll> last;
	rep(i, n) {
		ll x = a[i];
		if (last[x] + 1 < i) {
			m[get(0, 0, 1e5, last[x] + 1)] = 1;
		}
	}

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


class DSU {
public:
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
