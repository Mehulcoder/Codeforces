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



void solve()
{
    ll q;
    cin>>q;
    ll curr = 1;
    // trace(curr);
    multiset<pair<ll, ll>> m;
    multiset<pair<ll, ll>> qu;
    while(q--){
        ll a; cin>>a;
        ll b;
        if(a==1){
            cin>>b;
            qu.insert({curr, -b});
            m.insert({-b, curr++});
        }else if (a == 2)
        {
            cout<<qu.begin()->first<<" ";
            m.erase(m.find({qu.begin()->second, qu.begin()->first}));
            qu.erase(qu.begin());
        }else{
            cout<<m.begin()->second<<" ";
            qu.erase({m.begin()->second, m.begin()->first});
            m.erase(m.begin());
        }
    }

    cout<<endl;
    return;
}

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    
    while (t--)
    {
        solve();
    }

    return 0;
}