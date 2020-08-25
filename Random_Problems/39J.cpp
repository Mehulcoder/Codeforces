/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;

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
const ll MOD = 1e9 + 9;


void solve() {
	string a, b; cin >> a >> b;
	ll ind;
	bool ok = 0, flag = 0;

	rep(i, b.size()) {
		if (a[i] != b[i]) {
			flag = 1;
			ind = i;
			break;
		}
	}

	if (flag == 1) {
		fr(i, ind + 1, a.size() - 1) {
			if (a[i] != b[i - 1]) {
				cout << 0 << '\n';
				return;
			}
		}
	}

	if (flag != 1) ind = b.size(), flag = 1;
	ll left = ind, right = ind;

	while (left > 0 && a[left - 1] == a[left]) left--;
	while (right + 1 < a.size() - 1  && a[right + 1] == a[right]) right++;

	cout << right - left + 1 << '\n';

	fr(i, left, right) cout << i + 1 << ' ';
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