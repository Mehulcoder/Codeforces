/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define vset(v, n, val) v.clear(); v.resize(n, val)
#define INF 4557430888798830399ll
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define trav(a, x) for(auto& a : x)
/*
* Same rerooting idea as :https://codeforces.com/contest/1324/submission/90631691
* Calculate the ans for root, shift the root and get the ans for each of it's children
* by shifting the root to them(each in O(logn)). Usually this idea is applied when
* we want to explore all the cases.
*/
ll n;
vvll edges2;
vector<set<ll>> edges1;
vector<bool> visited;
vll dp, dp2, anss;

void dfs2(ll root, ll parent = -1) {
	dp2[root] = dp[root];

	trav(child, edges2[root]) {
		if (child == parent) continue;
		dp[root] -= dp[child];
		dp[child] += dp[root];
		if (edges1[child].find(root) == edges1[child].end()) dp[child]++;
		else dp[child]--;

		dfs2(child, root);

		if (edges1[child].find(root) == edges1[child].end()) dp[child]--;
		else dp[child]++;
		dp[child] -= dp[root];
		dp[root] += dp[child];
	}
	return;
}

void dfs(ll root, ll parent = -1) {
	visited[root] = 1;
	ll count = 0;
	trav(child, edges2[root]) {
		if (child == parent) continue;
		if (edges1[root].find(child) == edges1[root].end()) count++;
		dfs(child, root);
		count += dp[child];
	}

	dp[root] = count;
	return;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	cin >> n;

	vset(edges2, n, vll(0));
	edges1.resize(n);
	vset(visited, n, 0);
	vset(dp, n, 0);
	vset(dp2, n, 0);

	rep(i, n - 1) {
		ll a, b; cin >> a >> b;
		a--; b--;
		edges1[a].insert(b);
		edges2[a].push_back(b);
		edges2[b].push_back(a);
	}

	dfs(0);
	dfs2(0);

	ll mini = *min_element(all(dp2));
	cout << mini << '\n';
	rep(i, n) {
		if (dp2[i] == mini)cout << i + 1 << ' ';
	}
	cout <<  '\n';

	return 0 ;
}