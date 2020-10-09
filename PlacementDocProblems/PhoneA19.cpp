/*
Author: Mehul Chaturvedi
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define vll vector<long long>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
const ll MOD = 1e9 + 7;


// Assuming the max value of n<=1e5
// If not, then use map in place of array dp

/*
* Can very easily be proved with simple inequalities that
* a number k will be jth element of ith row (1 based index)
* where i = ceil((sqrtl(1.0 + 8.0 * num) - 1.0) / 2.0)
* and j = num - (i * i - i) / 2.
* Rest is recursion.
*/

const ll N = 500;
bool dp[N][N];
ll get(ll i, ll j) {
	if (j > i || j <= 0) return 0;
	if (dp[i][j] == 1) return 0;
	if (i == 1) {
		dp[i][j] = 1;
		return 1;
	}

	ll k = (j + (i * i - i) / 2);
	ll ans = k;
	ans += get(i - 1, j - 1) + get(i - 1, j);

	dp[i][j] = 1;
	return ans % MOD;
}

void solve() {
	ll num; cin >> num;
	memset(dp, 0, sizeof(dp));
	ll i = ceil((sqrtl(1.0 + 8.0 * num) - 1.0) / 2.0);
	ll j = num - (i * i - i) / 2;

	cout << get(i, j) << '\n';

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