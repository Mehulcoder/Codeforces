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

pll pos;
ll n, m, j;
vector<string> arr;
bool vis[45][45];
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};
void solve() {
	cin >> n >> m >> j;
	fil(vis, 0);
	arr.resize(n);
	rep(i, n) {
		cin >> arr[i];
		rep(j, m) {
			if (arr[i][j] == '@') pos = {i, j};
		}
	}

	j /= 2;
	queue<vll> q;
	q.push({pos.f, pos.s, 0});
	while (!q.empty()) {
		auto temp = q.front();
		pll curr = {temp[0], temp[1]};
		ll spikesHit = temp[2];
		q.pop();
		if (vis[curr.f][curr.s]) continue;
		vis[curr.f][curr.s] = 1;

		if (arr[curr.f][curr.s] == 'x' && spikesHit <= j) {
			cout << "SUCCESS" << '\n';
			return;
		}

		if (spikesHit <= j) {
			rep(k, 4) {
				ll ni = curr.f + dx[k];
				ll nj = curr.s + dy[k];
				if (!(ni >= 0 && ni < n && nj >= 0 && nj < m)) continue;
				if (arr[ni][nj] == '.' || arr[ni][nj] == 'x') {
					q.push({ni, nj, spikesHit});
				} else if (arr[ni][nj] == 's') {
					q.push({ni, nj, spikesHit + 1});
				}
			}
		}
	}


	cout << "IMPOSSIBLE" << '\n';
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