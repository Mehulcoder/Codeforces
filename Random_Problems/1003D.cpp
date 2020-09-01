/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)

/*
* Use greedy. Because all less values of coins are divisors of all
* greater values of coins. Let's say I want to make the sum equal to B
* I have say two options a1 and a2. Where a2 = (2^k)*a1. Which one should
* I try to choose first if say B is larger than them both?
* I will choose a2 as many times because if we choose  a1, I have to take
* it more than 2^k1 times, which is too much. We can do the same work with less
* coins using a2.
*/

void solve() {
	ll n, q; cin >> n >> q;

	vll a(n, 0), cnt(30, 0), poww(31, 1);
	rep(i, 31) {
		if (i == 0) continue;
		poww[i] = poww[i - 1] * 2;
	}

	rep(i, n) {
		cin >> a[i];
		cnt[floor(log2(a[i]))]++;
	}

	rep(i, q) {
		ll ans = 0, b;
		cin >> b;

		repr(i, 30) {
			ll reqdCount = (b / poww[i]);
			b -= min(cnt[i], reqdCount) * poww[i];
			ans += min(cnt[i], reqdCount);
		}

		if (b != 0) cout << -1 << '\n';
		else cout << ans << '\n';
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