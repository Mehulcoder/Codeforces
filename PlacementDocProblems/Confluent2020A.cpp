/*
Author: Mehul Chaturvedi
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
#define f first
#define s second
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define vset(v, n, val) v.clear(); v.resize(n, val)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

vector<string> grid;
set<pll> vis;
ll n, m, k;

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

bool isOk(ll i, ll j) {
	return (i < n && j < m && i >= 0 && j >= 0 && grid[i][j] == '.');
}

void solve() {
	cin >> n;
	cin >> k;

	vset(grid, n, "");
	vis.clear();
	rep(i, n) cin >> grid[i];
	m = grid[0].size();

	queue<vll> q;
	//x, y, dis
	q.push({0, 0, 0});
	while (!q.empty()) {
		auto temp = q.front();
		q.pop();
		if (temp[0] == n - 1 && temp[1] == m - 1) {
			cout << ((temp[2] <= k) ? "Yes" : "No") << '\n';
			return;
		}
		if (vis.find({temp[0], temp[1]}) != vis.end()) continue;
		vis.insert({temp[0], temp[1]});

		rep(k, 4) {
			ll ni = temp[0] + dx[k];
			ll nj = temp[1] + dy[k];

			if (isOk(ni, nj)) q.push({ni, nj, temp[2] + 1});
		}
	}

	cout << "No" << '\n';
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