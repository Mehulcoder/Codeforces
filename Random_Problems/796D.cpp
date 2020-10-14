/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
#define f first
#define s second
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define trav(a, x) for(auto& a : x)

const ll N = 3e5 + 10;
ll n, k, d;
vvll edges;
vector<bool> vis;
queue<pll> q;
map<pll, ll> e;

/*
* No use of D here. Why? As currently each place has an accesible station
* We can just ask k persons to stand at each station. Each of them will move
* one by one, making sure not going back where it came from. And mark the place
* before leaving. Now in it has already been marked. Just cut the path prom that
* city and where your last city was. Why? As it can be saved by other station.
*/

void solve() {
	cin >> n >> k >> d;
	edges.resize(n);
	vis.resize(N, 0);

	rep(i, k) {
		ll p; cin >> p;
		p--;
		q.push({p, -1});
	}


	rep(i, n - 1) {
		ll u, v;
		cin >> u >> v;
		u--; v--;

		edges[u].push_back(v);
		edges[v].push_back(u);
		e[ {u, v}] = i + 1;
		e[ {v, u}] = i + 1;
	}

	vll ans;
	while (!q.empty()) {
		auto temp = q.front();
		ll par = temp.s;
		ll curr = temp.f;
		q.pop();

		if (vis[curr]) continue;
		vis[curr] = 1;

		trav(child, edges[curr]) {
			if (child == par) continue;
			if (vis[child]) ans.push_back(e[ {curr, child}]);
			else q.push({child, curr});
		}
	}

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
	while (t--) {
		solve();
	}

	return 0 ;
}