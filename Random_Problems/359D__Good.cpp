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

void solve() {
	int n, maxi = 0, cnt, i = 0;
	cin >> n;
	int a[300005], ans[300005];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	while (i < n) {
		int l = i, r = i;
		while (l > 0 && (a[l - 1] % a[i] == 0))l--;
		while (r < n - 1 && (a[r + 1] % a[i] == 0))r++;
		int length = (r - l);
		i = r + 1;
		if (length > maxi)
			cnt = 0, maxi = length;
		if (length == maxi)
			ans[cnt++] = l + 1;
	}
	cout << cnt << " " << maxi << endl;
	for (int i = 0; i < cnt; i++)
		cout << ans[i] << " ";
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