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
	vll arr;

	node(vll val) {
		arr = val;
	}

};

vector<ll> v;
vector<node> t;
ll n, m;
ll anss;

node help(node left, node right) {
	vll arr1 = left.arr;
	vll arr2 = right.arr;

	vll arr0;
	arr0.resize(arr1.size() + arr2.size());
	merge(all(arr1), all(arr2), arr0.begin());
	node res(arr0);

	return res;
}

void build(ll start, ll tl, ll tr) {
	if (tl + 1 == tr) {
		//Only one element in the vector
		t[start] = node({v[tl]});
		return;
	}

	ll mid = (tl + tr) / 2;
	build(2 * start + 1, tl, mid);
	build(2 * start + 2, mid, tr);
	node left = t[2 * start + 1];
	node right = t[2 * start + 2];
	t[start] =  help(left, right);
	return;
}


node get(ll start, ll tl, ll tr, ll l, ll r, ll num) {
	if (tl >= r || tr <= l) {
		anss = 0;
		return node({});
	}

	if (l <= tl && r >= tr) {
		auto &temp = t[start].arr;
		anss = temp.end() - upper_bound(all(temp), num);
		return t[start];
	}

	ll mid = (tl + tr) / 2;
	node left = get(2 * start + 1, tl, mid, l, r, num);
	node right = get(2 * start + 2, mid, tr, l, r, num);
	node ans = help(left, right);

	auto &temp = ans.arr;
	anss = temp.end() - upper_bound(all(temp), num);
	return ans;
}

void solve() {
	cin >> n;
	v.clear();
	v.resize(n, 0);
	t.clear();
	t.resize(4 * n, node({}));
	rep(i, n) {
		cin >> v[i];
	}

	build(0, 0, n);
	ll q; cin >> q;

	while (q--) {
		ll l, r, k;
		cin >> l >> r >> k;
		auto ans = get(0, 0, n, l, r + 1, k);
		cout << anss << '\n';
	}

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