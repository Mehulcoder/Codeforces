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

const ll N  = 305;

ll n;
ll a[N];
ld dp[N][N][N];

ld get(ll one, ll two, ll three) {
	ll zero = (n - one - two - three);
	if (zero == n || one < 0 || two < 0 || three < 0) {
		return 0;
	}

	ld &anss = dp[one][two][three];
	if (anss != -1) return anss;


	ld ans = 1.0 + get(one - 1, two, three) * ((ld)one / n);
	ans += get(one + 1, two - 1, three) * ((ld)two / n);
	ans += get(one, two + 1, three - 1) * ((ld)three / n);

	ans /= (1.0 - (ld)zero / n);

	return anss = ans;
}

void solve() {
	cin >> n;
	rep(i, n) cin >> a[i];
	ll one, two, three;
	one = two = three  = 0ll;

	rep(i, N) {
		rep(j, N) {
			rep(k, N) {
				dp[i][j][k] = -1;
			}
		}
	}

	rep(i, n) {
		if (a[i] == 1)one++;
		else if (a[i] == 2) two++;
		else if (a[i] == 3) three++;
	}

	cout << setprecision(12);
	cout << fixed;
	cout << get(one, two , three) << '\n';

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