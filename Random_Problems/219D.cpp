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
vvll edges1, edges2;
vector<bool> visited;

void dfs(ll root, ll parent = -1) {
	visited[root] = 1;
	trav(child, edges2[root]) {

	}
}

void solve() {
	cin >> n;

	vset(edges2, n, vll(0);)
	vset(edges1, n, vll(0);)
	vset(visited, n, 0);

	rep(i, n - 1) {
		ll a, b; cin >> a >> b;
		a--; b--;
		edges1[a].push_back(b);
		edges2[a].push_back(b);
		edges2[b].push_back(a);
	}

	rep(i, n) {
		if (!visited[i]) {
			dfs(i);
			dfs2(i);
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