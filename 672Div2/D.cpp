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
const ll MOD = 998244353 ;

/*
*       For every endPoint, add the number of ways to choose k lamps
*       Such that the segment(call it p) with that endpoint is one of the k segments
*       Which basically leaves you to choose the k-1 segments that pass through
*       that end point, other than p.
*/

const ll N = 3e5 + 10;
vector<ll> inv;
vector<ll> fact;
vector<ll> invFact;

bool mySort(pll a, pll b) {
    if (a.f < b.f) return 1;
    if (a.f == b.f)
        if (a.s > b.s) return 1;
    return 0;
}

void precalc() {
    inv.resize(N, 1);
    fact.resize(N, 1);
    invFact.resize(N, 1);

    fr(i, 2, N - 1) {
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = (invFact[i - 1] * inv[i]) % MOD;
    }

    return;
}

ll ncr(ll n, ll r, ll mod = MOD) {
    if (r > n) {
        return 0;
    }
    return (((fact[n] * invFact[n - r]) % mod) * invFact[r]) % mod;
}

void solve() {
    ll n, k; cin >> n >> k;

    vector<pll> v;

    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, -1});
    }

    sort(all(v), mySort);
    ll counter = 0, ans = 0;

    rep(i, 2 * n) {
        counter += v[i].s;
        if (v[i].s == -1) {
            ans += ncr(counter, k - 1);
            ans %= MOD;
        }
    }

    cout << (ans + MOD) % MOD << '\n';
    return;

}

int main(int argc , char ** argv) {
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    ll t = 1;
    precalc();
    while (t--) {
        solve();
    }

    return 0 ;
}
