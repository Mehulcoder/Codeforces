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

ll dy[4] = {0, -1, 1, 0};
ll dx[4] = { 1, 0, 0, -1};
vector<char> mpp = {'D', 'L', 'R', 'U'};
vector<string> edges;
vvll dis;
const ll N = 1e3 + 1;
bool vis[N][N];

/*
* Greedy: Try to follow the lexographically smallest till possible
* Make sure that you have enough steps left (in worst case you'll
* trace back the path you came from.)
*/

//PS: Getting back to CF feels so nice. Fu*k Leetcode

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;

	dis.resize(n, vll(m, INF));

	if (k % 2) {
		cout << "IMPOSSIBLE" << '\n';
		return;
	}

	fil(vis, 0);

	edges.resize(n);
	pll pos = { -1, -1};
	rep(i, n) {
		cin >> edges[i];
		rep(j, edges[i].size()) {
			if (edges[i][j] == 'X') {
				pos = {i, j};
				edges[i][j] = '.';
			}
		}
	}

	queue<vector<ll>> q;
	q.push({pos.f, pos.s, 0});
	while (!q.empty()) {
		auto temp = q.front();
		q.pop();

		if (vis[temp[0]][temp[1]]) continue;
		vis[temp[0]][temp[1]] = 1;
		dis[temp[0]][temp[1]] = temp[2];

		rep(kk, 4) {
			ll ni = temp[0] + dx[kk];
			ll nj = temp[1] + dy[kk];
			if (ni < n && ni >= 0 && nj < m && nj >= 0 && edges[ni][nj] == '.') {
				q.push({ni, nj, temp[2] + 1});
			}
		}
	}


	string ans;
	vll temp = {pos.f, pos.s, 0};
	while (temp[2] < k) {
		bool flag = 0;
		rep(kk, 4) {
			ll ni = temp[0] + dx[kk];
			ll nj = temp[1] + dy[kk];
			if (ni < n && ni >= 0 && nj < m && nj >= 0 && edges[ni][nj] == '.' && (dis[ni][nj] <= k - temp[2] - 1)) {
				temp = {ni, nj, temp[2] + 1};
				ans += mpp[kk];
				flag = 1;
				break;
			}
		}
		if (!flag) {
			cout << "IMPOSSIBLE" << '\n';
			return;
		}
	}

	cout << ans << '\n';
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