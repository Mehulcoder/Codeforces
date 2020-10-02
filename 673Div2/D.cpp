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

/*
* Total sum remains constant ---> sum must be divisble by n
* Taking i = 1. We can make all other elements 0. How?
* Since we can now only add in a[j], let us try to make
* a[j] a multiple of j, so that later we can take i=j, and
* subtract factor*i, where factor*i = newValueOf a[j]

* So to make it a multiple of j, take x = j-(a[j]%j)
* and subtract x from a[1].

* Now every element other than a[1] can easily be made 0.

* Now a[1] == SUM. Now divide that sum into n-1 elements

* Total operations ---> 3*n-3
*/

void solve() {
        ll n;
        cin >> n;

        ll array[n + 1];
        ll sum = 0;

        fr(i, 1, n) {
                cin >> array[i];
                sum += array[i];
        }

        if ((sum % n) != 0) {
                cout << "-1\n";
                return;
        }
        vector< pair<ll, pll > > ans;
        ll avg = sum / n;

        fr(i, 2, n) {
                if ((array[i] % i) != 0) {
                        ll val = i - (array[i] % i);
                        ans.push_back({1, {i, val}});

                        array[i] += val;
                        array[1] -= val;
                }

                ans.push_back({i, {1, array[i] / i}});
                array[1] += array[i];
                array[i] = 0;
        }

        fr(i, 2, n) {
                ans.push_back({1, {i, sum / n}});
        }

        cout << ans.size() << "\n";
        rep(i, ans.size()) {
                cout << ans[i].f << " " << ans[i].s.f << " " << ans[i].s.s << "\n";
        }

        return;
}

int main(int argc , char ** argv) {
        ios_base::sync_with_stdio(false) ;
        cin.tie(NULL) ;

        ll t = 1;
        cin >> t;
        while (t--) {
                solve();
        }

        return 0 ;
}