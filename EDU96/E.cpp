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

class node {
public:
	ll add;
	node(ll val) {
		add = val;
	}

};

vector<node> t;
vector<bool> marked;
ll n;

void sett(ll start, ll tl, ll tr, ll pos, ll val) {
	if (tl + 1 == tr) {
		t[start].add = val;
		return;
	}

	ll mid = (tl + tr) / 2;
	if (pos < mid) {
		sett(2 * start + 1, tl, mid, pos, val);
	} else {
		sett(2 * start + 2, mid, tr, pos, val);
	}

	t[start] = node(t[2 * start + 1].add + t[2 * start + 2].add);

	return;
}


node get(ll start, ll tl, ll tr, ll l, ll r) {
	if (l >= r) return node(0);
	if (l == tl && r == tr) {
		return t[start];
	}
	ll mid = (tl + tr) / 2;
	return node(get(start * 2 + 1, tl, mid, l, min(r, mid)).add
	            + get(start * 2 + 2, mid, tr, max(l, mid), r).add);
}

map<ll, set<ll>> m;
void solve() {
	cin >> n;
	string s; cin >> s;
	string s1 = s;
	reverse(all(s1));
	rep(i, n) m[s[i] - 'a'].insert(i);

	vll arr(n, -1);
	map<ll, ll> place;
	ll curr = 0;
	rep(i, n) {
		ll pos = *(m[s1[i] - 'a'].begin());
		m[s1[i] - 'a'].erase(m[s1[i] - 'a'].begin());
		arr[pos] = curr++;
		place[arr[pos]] = pos;
	}

	t.resize(4 * n, node(0));
	ll ans = 0;

	rep(i, n) {
		ll temp = get(0, 0, n, arr[i] + 1, n).add;
		ans += temp;
		sett(0, 0, n, arr[i], 1);
	}
	cout << ans << '\n';
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