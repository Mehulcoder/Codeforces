/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vll vector<long long>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fil(ar, val) memset(ar, val, sizeof(ar))

const ll N = 1e5 + 10;
string s = "hard", inp;
vll a;
ll dp[N][4];


ll get(ll end, ll last) {
	if (end < 0 || last < 0) return 0;

	ll &ans = dp[end][last];
	if (ans != -1) return ans;

	ans = 0;

	if (inp[end] == s[last]) {
		if (last == 0) {
			ans = a[end] + get(end - 1, last);
		} else {
			ll temp1 = a[end] + get(end - 1, last);
			ll temp2 = get(end - 1, last - 1);
			ans = min(temp1, temp2);
		}
	} else {
		ans = get(end - 1, last);
	}

	return ans;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	fil(dp, -1);

	ll n; cin >> n;
	cin >> inp;

	a.resize(n, 0);
	rep(i, n) cin >> a[i];

	cout << get(n - 1, 3) << '\n';

	return 0 ;
}