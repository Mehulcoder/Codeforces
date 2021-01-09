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
#define vset(v, n, val) \
    v.clear();          \
    v.resize(n, val)
#define INF 4557430888798830399ll
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define trav(a, x) for (auto &a : x)
#define fil(ar, val) memset(ar, val, sizeof(ar))
const ll MOD = 1e9 + 7;
const ll N = 3e5 + 10;
vector<ll> inv;
vector<ll> fact;
vector<ll> invFact;
vector<ll> spf;

void precalc() {
    inv.resize(N, 1);
    fact.resize(N, 1);
    invFact.resize(N, 1);
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

    fr(i, 2, N - 1) {
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = (invFact[i - 1] * inv[i]) % MOD;
    }

    return;
}

///PreCalculate NcR
ll ncr(ll n, ll r, ll mod=MOD){
        if (r > n) {
        return 0;
    }
    return (((fact[n]*invFact[n-r])%mod)*invFact[r])%mod;
}

void solve()
{
    std::cout << "Hello" << std::endl;
}

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}