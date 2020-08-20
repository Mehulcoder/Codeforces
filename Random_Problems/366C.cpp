/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define vset(v, n, val) v.clear(); v.resize(n, val)
#define INF 4557430888798830399ll
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fil(ar, val) memset(ar, val, sizeof(ar))

const ll N = 105;
const ll offset = 1e5 + 5;
vll a, b, diff;
ll dp[2 * offset][N];

/*
* Make an array a[i]-b[i]*k, now we need to choose
* The subsequence of this array that sums to zero
* and maximises the sum of a[i]
*/
ll get(ll sum, ll end) {
	if (end == -1) {
		if (sum == 0) return 0;
		else return -INF;
	}

	ll &ans = dp[sum + offset][end];
	if (ans != -1) return ans;

	ans = max(a[end] + get(sum - diff[end], end - 1), get(sum, end - 1));
	return ans;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll n, k; cin >> n >> k;
	vset(a, n, 0);
	vset(b, n, 0);

	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	rep(i, n) diff.push_back(a[i] - k * b[i]);

	fil(dp, -1);
	ll ans = get(0, n - 1);
	if (ans <= 0) cout << -1 << '\n';
	else cout << ans << '\n';

	return 0 ;
}