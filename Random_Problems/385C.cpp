/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vll vector<long long>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

const ll N = 1e7 + 10;
vector<ll> spf;
vll cnt(N, 0);
vll val(N, 0);

void precalc() {

	spf.resize(N, 0);
	spf[1] = 1;
	fr(i, 2, N - 1) {
		if (!spf[i]) {
			spf[i] = i;
			cnt[i] += val[i];
			for (int j = 2 * i; j <= N - 1; j += i) {
				if (!spf[j]) {
					spf[j] = i;
				}
				cnt[i] += val[j];
			}
		}
	}

	return;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll n, m; cin >> n;
	vll x(n);

	rep(i, n) cin >> x[i], val[x[i]]++;
	precalc();

	cin >> m;
	rep(i, N) if (i > 0)cnt[i] += cnt[i - 1];

	rep(i, m) {
		ll l, r; cin >> l >> r;
		r = min(r, N - 1);
		l = min(l, N - 1);
		cout << cnt[r] - cnt[l - 1] << '\n';
	}

	return 0 ;
}