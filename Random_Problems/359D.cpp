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

#ifdef mehul
template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T>
void __p(std::vector<T> a) { cout << "{ "; for (auto p : a) __p(p); cout << "}"; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.first); __p(a.second); cout << "}"; }
template<typename T, typename F>
void __p(std::vector<pair<T, F>> a) { cout << "{ "; for (auto p : a) __p(p); cout << "}"; }
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) { __p(a1); __p(a...); }
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout << name << " : "; __p(arg1); cout << endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	int bracket = 0, i = 0;
	for (; ; i++)
		if (names[i] == ',' && bracket == 0)
			break;
		else if (names[i] == '(')
			bracket++;
		else if (names[i] == ')')
			bracket--;
	const char *comma = names + i;
	cout.write(names, comma - names) << " : ";
	__p(arg1);
	cout << "| ";
	__f(comma + 1, args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: "<< fixed << double(clock() - begtime)*1000/CLOCKS_PER_SEC << setprecision(12) << " ms\n\n";
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif


class node {
public:
	ll gcdd;

	node(ll val) {
		gcdd = val;
	}

};

vector<ll> v;
vector<node> t;
ll n, m;

node help(node left, node right) {
	node res(__gcd(left.gcdd, right.gcdd));
	return res;
}

void build(ll start, ll tl, ll tr) {
	if (tl + 1 == tr) {
		t[start] = node(v[tl]);
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


node get(ll start, ll tl, ll tr, ll l, ll r) {
	if (l == tl && r == tr) {
		return t[start];
	}

	ll mid = (tl + tr) / 2;
	node left = get(2 * start + 1, tl, mid, l, min(mid, r));
	node right = get(2 * start + 2, mid, tr, max(mid, l), r);
	return help(left, right);
}

bool check(ll len) {
	multiset<ll> s;
	rep(i, len) {
		s.insert(v[i]);
	}

	ll g = get(0, 0, n, 0, len).gcdd;
	trace(len);
	bool ok = (g == (*s.begin()));

	ll curr = 0;
	while (curr + len < n) {
		s.erase(s.find(v[curr]));
		s.insert(v[curr + len]);
		curr++;

		g = get(0, 0, n, curr, curr + len).gcdd;
		ok = ok || (g == *(s.begin()));
	}

	return ok;
}


void solve() {
	cin >> n;
	vset(v, n, 0);
	t.clear();
	t.resize(4 * n, node(1));

	rep(i, n) cin >> v[i];

	build(0, 0, n);
	ll lo = 1;
	ll hi = n;
	ll ans = 1;

	cout << get(0, 0, n, 1, 4).gcdd << '\n';
	return;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (check(mid)) {
			lo = mid + 1;
			ans = max(ans, mid);
		} else {
			hi = mid - 1;
		}
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