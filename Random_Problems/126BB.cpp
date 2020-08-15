
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
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
//Power Function O(log(n))
ll poww(ll a, ll b, ll mod = MOD)
{
	if (b == 0)
		return 1;
	ll ans = poww(a, b / 2, mod);
	if (b % 2 == 0)
		return (ans * ans) % mod;
	return (((ans * ans) % mod) * a) % mod;
}

ll gcdExtended(ll a, ll b, ll &x, ll &y) {
	if (a == 0)
	{
		x = 0;
		y = 1;
		return b;
	}

	ll x1, y1;
	ll d = gcdExtended(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

ll modInverse(ll a, ll mod = MOD) {
	ll x, y;
	ll d = gcdExtended(a, mod, x, y);
	if (d != 1)
	{
		return -1;
	}

	return (x % mod + mod) % mod;
}

vll getHash(string &s, ll mod = MOD) {

	ll n = s.size(), pPow = 1;
	vll hash(n, 0);
	rep(i, n) {
		char c = s[i];
		hash[i] = ((c - 'a' + 1) * pPow) % mod;
		if (i > 0)hash[i] += hash[i - 1];
		pPow = (31 * pPow) % mod;
	}

	return hash;
}

const ll N = 1e6 + 10;
vector<ll> inv;
vector<ll> powers;

void precalc() {
	inv.resize(N, 1);
	powers.resize(N, 1);
	fr(i, 1, N - 1) powers[i] = (powers[i - 1] * 31) % MOD;
	fr(i, 0, N - 1) inv[i] = modInverse(powers[i]);
	return;
}

/*

* Make an array and put in all the possible lengths into it
* such that prefix of that length is equal to the suffix.
* Now sort the length array and binary search over the array
* In each step, check if you can find the infix same as prefix


* NOTE: Precalculate the powers and their inverse for getting saved
* from TLE. However there must be some faster way to do that. If you could
* Help me further optimize it. DM ME.

* For hashing tutorial: https://cp-algorithms.com/string/string-hashing.html
*/

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL);
	precalc();
	string s; cin >> s;
	ll n = s.size(), length = 0;
	vll possible;

	vll hashPre = getHash(s);
	fr(i, 1, n - 2) {
		ll pref = (2 * MOD + hashPre[i - 1]) % MOD;
		ll suff = (((2 * MOD + (MOD + hashPre[n - 1] - hashPre[n - i - 1]) % MOD) % MOD) * inv[n - i]) % MOD;
		if (pref == suff)possible.push_back(i);
	}

	sort(all(possible));
	ll lo = 0, hi = possible.size() - 1;
	while (lo <= hi && possible.size() > 0) {
		ll mid = (lo + hi) / 2;
		ll leng = possible[mid];
		bool ok = 0;
		fr(i, 1, n - leng - 1) {
			ll inFix = (2 * MOD + ((hashPre[i + leng - 1] - hashPre[i - 1]) % MOD) * inv[i]) % MOD;
			ll pref = (2 * MOD + hashPre[leng - 1]) % MOD;
			if (inFix == pref) {
				ok = 1;
				break;
			}
		}
		if (ok)lo = mid + 1, length = max(length, leng);
		else hi = mid - 1;
	}

	cout << ((length > 0) ? (s.substr(0, length)) : ("Just a legend")) << '\n';
	return 0 ;
}

