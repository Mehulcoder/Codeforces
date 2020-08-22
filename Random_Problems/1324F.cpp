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
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define trav(a, x) for(auto& a : x)

ll n;
vll a, ans, dp;
vvll edges;
/*
Rerooting Technique:https://codeforces.com/blog/entry/68142?#comment-590195

* Calculte the ans for the root 0, using dfs
* Now shift the root one by one to the childs of
* prevRoot. And calculate the ans, for each of them
* in O(1)

* When shifting the root. Subtract the contri of that child c1 from dp[prevRoot].
* Make that child as root. Add the contri of prevRoot for that child c1

* Call dfs2 on the childs of the child c1

* Roll Back: IMPORTANT: First, Remove contri of prev root from the child c1
* Add the contri of that child c1 to the dp[prevRoot]

* Repeat second step for the other childs of prevRoot.
*/

void dfs(ll root, ll parent = -1) {
	dp[root] = a[root];
	trav(child, edges[root]) {
		if (child == parent) continue;
		dfs(child, root);
		dp[root] += max(0ll, dp[child]);
	}
	return;
}

void dfs2(ll root, ll parent = -1) {
	ans[root] = dp[root];
	trav(child, edges[root]) {
		if (child == parent)continue;
		dp[root] -= max(0ll, dp[child]);
		dp[child] += max(0ll, dp[root]);
		dfs2(child, root);
		dp[child] -= max(0ll, dp[root]);
		dp[root] += max(0ll, dp[child]);
	}

	return;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	cin >> n;

	vset(a, n, 0);
	vset(edges, n, vll(0));
	vset(ans, n, -1);
	vset(dp, n, -1);

	rep(i, n) {
		cin >> a[i];
		if (a[i] == 0) a[i] = -1;
	}
	rep(i, n - 1) {
		ll p, q;
		cin >> p >> q;
		p--; q--;
		edges[p].push_back(q);
		edges[q].push_back(p);
	}

	dfs(0);
	dfs2(0);
	trav(elem, ans) cout << elem << ' ';
	cout << '\n';

	return 0 ;
}