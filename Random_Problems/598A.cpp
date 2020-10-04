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


ll n, m, k;
vector<string> mat;
vvll ans, visited;
vector < pll > s;


ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};


bool isValid(ll i, ll j) {
	return (i >= 0 && i < n && j >= 0 && j < m && !visited[i][j]);
}

ll dfs(ll i, ll j) {
	s.push_back({i, j});
	visited[i][j] = 1;
	ll ans = 0;
	rep(k, 4) {
		ll ni = i + dx[k];
		ll nj = j + dy[k];
		if (isValid(ni, nj)) {
			if (mat[ni][nj] == '*') ans++;
			else ans += dfs(ni, nj);
		}
	}

	return ans;
}

void solve() {
	cin >> n >> m >> k;
	mat.resize(n);
	ans.resize(n, vll(m, 0));
	visited.resize(n, vll(m,  0));

	rep(i, n) cin >> mat[i];

	rep(i, n) {
		rep(j, m) {
			if (!visited[i][j] && mat[i][j] == '.') {
				s.clear();
				ll temp = dfs(i, j);
				trav(elem, s) {
					ans[elem.f][elem.s] = temp;
				}
			}
		}

	}


	rep(i, k) {
		ll x, y;
		cin >> x >> y;
		x--; y--;
		cout << ans[x][y] << '\n';
	}

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