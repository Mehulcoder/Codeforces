#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
#define f first
#define s second
#define vll vector<long long>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define trav(a, x) for(auto& a : x)

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll n, m; cin >> n;
	vll p(n), a(n), b(n);
	vector < set<pll> > v(3);

	rep(i, n) cin >> p[i];
	rep(i, n) cin >> a[i], v[a[i] - 1].insert({p[i], i});
	rep(i, n) cin >> b[i], v[b[i] - 1].insert({p[i], i});

	cin >> m;
	rep(i, m) {
		ll c; cin >> c; c--;
		if (!v[c].empty()) {
			auto temp = *(v[c].begin());
			cout << temp.f << ' ';
			trav(sett, v) if (sett.find(temp) != sett.end()) sett.erase(temp);
		} else cout << -1 << ' ';
	}
	cout << '\n';
	return 0 ;
}