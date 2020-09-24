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


string s;
set<string> st;
ll n;
bool vis[10010][4];

void get(ll end, ll len, string prev) {
	if (end - len + 1 < 5 || vis[end][len]) return;

	string t = s.substr(end - len + 1, len);
	if (t == prev) return;
	vis[end][len] = 1;

	st.insert(t);
	get(end - len, 2, t);
	get(end - len, 3, t);

	return;
}

void solve() {
	cin >> s;
	n = s.size();
	fil(vis, 0);

	get(n - 1, 2, "");
	get(n - 1, 3, "");

	cout << st.size() << '\n';
	trav(elem, st) {
		cout << elem << '\n';
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