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
        v.clear();      \
        v.resize(n, val)
#define INF 4557430888798830399ll
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define trav(a, x) for (auto &a : x)
#define fil(ar, val) memset(ar, val, sizeof(ar))
const ll MOD = 1e9 + 7;

bool isPrime(ll a)
{
        if (a == 1 || !a)
                return 0;

        for (int i = 2; i * i <= a; i++)
        {
                if (a % i == 0)
                        return 0;
        }

        return 1;
}
int n, t;
vector<int> ans[1007];
int res[1007];
void solve()
{
        auto f = [&](int u) {
                for (int i = 2; i <= u; ++i)
                {
                        if (u % i == 0)
                                return i;
                }
                return 0;
        };
        cin >> n;
        for (int i = 1; i <= 1000; ++i)
                ans[i].clear();
        for (int i = 1; i <= n; ++i)
        {
                int u;
                cin >> u;
                ans[f(u)].push_back(i);
        }
        int ret = 0;
        for (int i = 1; i <= 1000; ++i)
        {
                if (ans[i].size())
                {
                        ++ret;
                        for (auto c : ans[i])
                        {
                                res[c] = ret;
                        }
                }
        }
        cout << ret << "\n";
        for (int i = 1; i <= n; ++i)
        {
                cout << res[i] << " ";
        }
        cout << "\n";

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