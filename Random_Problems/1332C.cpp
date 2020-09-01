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
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define trav(a, x) for(auto& a : x)

vvll edges;
vll visited;
string s;
ll dfs(ll root, vector<ll> &freq) {
	visited[root] = 1;
	freq[s[root] - 'a']++;

	trav(child, edges[root]) {
		if (visited[child]) continue;
		dfs(child, freq);
	}

	ll sum = 0;
	rep(i, 26) sum += freq[i];
	sum -= *max_element(all(freq));

	return sum;
}

void solve() {
	ll k, n, ans = 0ll;
	cin >> n >> k;

	vset(edges, n, vll(0));
	vset(visited, n, 0);

	cin >> s;

	rep(i, n) {
		if (i < n - i - 1) {
			edges[i].push_back(n - i - 1);
			edges[n - i - 1].push_back(i);
		}
		if (i != i + k && i + k < n) {
			edges[i].push_back(i + k);
			edges[i + k].push_back(i);
		}
	}

	rep(i, n) {
		if (!visited[i]) {
			vector<ll> freq(26, 0);
			ans += dfs(i, freq);
		}
	}

	cout << ans << '\n';
	return;
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