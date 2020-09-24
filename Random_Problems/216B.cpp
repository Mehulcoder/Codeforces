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
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define trav(a, x) for(auto& a : x)


/*
* Odd cycles will always make one child sit.
* Odd trees will create a diff of 1. So if
* odd trees are even they can counterbalance.
* Else one more member has to sit.
*/
ll n, m;
vvll edges;
vll vis;

ll dfs(ll root, bool &isCycle, ll par = -1) {
	vis[root] = 1;
	ll count = 1;

	trav(child, edges[root]) {
		if (child == par) continue;
		if (vis[child]) {
			isCycle = 1;
			continue;
		}
		count += dfs(child, isCycle, root);
	}

	return count;
}

void solve() {

}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	cin >> n >> m;
	edges.resize(n);
	vis.resize(n, 0);
	rep(i, m) {
		ll a, b; cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	ll oddTree = 0, ans = 0;
	rep(i, n) {
		if (!vis[i]) {
			bool isCycle = 0;
			ll len = dfs(i, isCycle);
			if (isCycle) {
				ans += len % 2;
			} else {
				oddTree = (oddTree + len) % 2;
			}
		}
	}

	cout << oddTree + ans << '\n';

	return 0 ;
}