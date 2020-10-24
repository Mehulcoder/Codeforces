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

void build(ll start, ll tl, ll tr) {
	if (tl + 1 == tr) {
		t[start] = node(0);
		return;
	}

	ll mid = (tl + tr) / 2;
	build(2 * start + 1, tl, mid);
	build(2 * start + 2, mid, tr);

	t[start] = node(0);
	return;
}

void push(ll start) {
	if (marked[start]) {
		t[start * 2 + 1].add += t[start].add;
		t[start * 2 + 2].add += t[start].add;
		t[start].add = 0;
		marked[start * 2 + 2] = marked[start * 2 + 1] = true;
		marked[start] = false;
	}
}


void sett(ll start, ll tl, ll tr, ll l, ll r) {
	if (l >= r) {
		return;
	}
	if (l == tl && r == tr) {
		(t[start].add)++;
		marked[start] = 1;
		return;
	}

	push(start);
	ll mid = (tl + tr) / 2;
	sett(2 * start + 1, tl, mid, l, min(r, mid));
	sett(2 * start + 2, mid, tr, max(l, mid), r);

	return;
}


node get(ll start, ll tl, ll tr, ll pos) {
	if (tr == tl + 1) return t[start];
	push(start);
	ll mid = (tl + tr) / 2;
	if (pos < mid) {
		return get(2 * start + 1, tl, mid, pos).add;
	} else {
		return get(2 * start + 2, mid, tr, pos).add;
	}
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
	marked.resize(4 * n, 0);
	build(0, 0, n);
	ll ans = 0;
	rep(i, n - 1) {
		ll ind = place[i];
		ll ad = get(0, 0, n, ind).add;
		ll nInd = ad + ind;
		ans += abs(nInd - i);
		sett(0, 0, n, 0, ind);

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