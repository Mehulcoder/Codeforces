/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define vll vector<long long>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define trav(a, x) for(auto& a : x)

ll N, m;
void solve() {
	vector<bool> valid(10, 1);
	rep(i, m) {
		ll a; cin >> a;
		valid[a] = 0;
	}

	queue<pair<ll, string>> q;
	vll v;
	rep(i, 10) {
		if (valid[i]) {
			if (i != 0) q.push({i, to_string(i)});
			v.push_back(i);
		}
	}
	vector<bool> vis(N + 10, 0);
	while (!q.empty()) {
		auto temp = q.front();
		q.pop();

		ll curr = temp.f % N;
		string num = temp.s;
		if (curr == 0) {
			bool ok = 0;
			cout << num << endl;
			return;
		}

		if (vis[curr]) continue;
		vis[curr] = 1;

		trav(elem, v) {
			if (!vis[(curr * 10 + elem + N) % N])
				q.push({(curr * 10 + elem + N) % N, num + to_string(elem)});
		}
	}

	cout << -1 << endl;
	return;

}

int main(int argc , char ** argv) {
	// ios_base::sync_with_stdio(false) ;
	// cin.tie(NULL) ;

	ll curr = 1;
	while (scanf("%lld%lld", &N, &m) == 2) {
		cout << "Case " << curr << ": ";
		solve();
		curr++;
	}

	return 0 ;
}