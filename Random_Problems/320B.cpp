/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;

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
const ll MOD = 1e9 + 9;

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


vector<pll> nodes;
vvll edges;
vector<bool> visited;

void addEdge(ll a, ll b) {
	ll newLastInd = nodes.size();
	nodes.push_back({a, b});
	fr(i, 0, nodes.size() - 2) {
		pll node = nodes[i];
		ll c = node.f;
		ll d = node.s;
		bool t1 = (a == c) || (b == d);
		bool t2  = a > c && d > a && b > d;
		bool t3 = c > a && d > b && b > c;
		if (t1 || t2 || t3) {
			edges[i].push_back(newLastInd);
			edges[newLastInd].push_back(i);
		}
	}
	return;
}

bool dfs(ll root, ll target, ll parent = -1) {
	visited[root] = 1;
	if (root == target) return 1;
	trav(child, edges[root]) {
		if (visited[child]) continue;
		if (dfs(child, target, root)) return 1;
	}

	return 0;
}

//Can I reach from nodes[x-1] to nodes[y-1]
void check(ll x, ll y) {
	x--; y--;
	vset(visited, 105, 0);
	if (dfs(x, y)) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
}

void solve() {
	ll n; cin >> n;
	nodes.clear();
	vset(edges, 105, vll(0));
	rep(i, n) {
		ll q, l, r;
		cin >> q >> l >> r;
		if (q == 2) {

			check(l, r);
		} else {
			addEdge(l, r);
		}
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