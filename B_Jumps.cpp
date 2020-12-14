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

/**
 * 4 <= 1+2+3
 * 1+2+3...+k = (k)*(k+1)/2
 * */

void solve()
{
    ll x;
    cin >> x;

    ll finalPos = 0;
    ll adder = 1, steps = 0;
    while (finalPos < x)
    {
        finalPos += adder++;
        steps++;
    }

    // trace(finalPos, steps);

    if (finalPos - x == 1)
    {
        std::cout << steps + 1 << std::endl;
    }
    else
    {
        std::cout << steps << std::endl;
    }

    return;
}

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}