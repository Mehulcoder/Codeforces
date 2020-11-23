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

ll n, m;
vector<string> a;
vector<pll> anss;
ll getCount(ll i, ll j) {
	ll ans = 0ll;
	fr(p, i, i + 1) {
		fr(q, j, j + 1) {
			ans += (a[p][q] == '1');
		}
	}

	return ans;
}

void get3(ll i, ll j) {

	fr(p, i, i + 1) {
		fr(q, j, j + 1) {
			if (a[p][q] == '1') {
				a[p][q] = '0';
				anss.push_back({p, q});
			}
		}
	}

	return;
}

void get2(ll i, ll j) {
	bool ok = 0;
	fr(p, i, i + 1) {
		fr(q, j, j + 1) {
			if (a[p][q] == '1' && !ok) {
				ok = 1;
				a[p][q] = '0';
				anss.push_back({p, q});
			} else if (a[p][q] == '0') {
				a[p][q] = '1';
				anss.push_back({p, q});
			}
		}
	}

	get3(i, j);

	return;
}

void get1(ll i, ll j) {
	int cnt = 0;
	fr(p, i, i + 1) {
		fr(q, j, j + 1) {
			if (a[p][q] == '0') {
				cnt++;
				if (cnt < 3) {
					a[p][q] = '1';
					anss.push_back({p, q});
				}
			} else {
				anss.push_back({p, q});
				a[p][q] = '0';
			}

		}
	}


	get2(i, j);

	return;
}

void get4(ll i, ll j) {
	ll cnt = 0ll;

	fr(p, i, i + 1) {
		fr(q, j, j + 1) {
			cnt++;
			if (a[p][q] == '1' && cnt < 4ll) {
				anss.push_back({p, q});
				a[p][q] = '0';
			}
		}
	}

	get1(i, j);
	return;
}

void solve() {
	cin >> n >> m;
	a.clear();
	anss.clear();
	a.resize(n);
	rep(i, n) cin >> a[i];


	rep(i, n - 1) {
		rep(j, m - 1) {
			ll cnt = getCount(i, j);
			if (cnt == 1) {
				get1(i, j);
			} else if (cnt == 2) {
				get2(i, j);
			} else if (cnt == 3) {
				get3(i, j);
			} else if (cnt == 4) {
				get4(i, j);
			}
		}
	}

	cout << anss.size() / 3 << '\n';
	ll count = 0;
	trav(elem, anss) {
		count++;
		cout << elem.f + 1 << ' ' << elem.s + 1;
		if (count == 3) {
			cout << endl;
			count = 0;
		} else {
			cout << ' ';
		}
	}
	// if (count == 3) {
	// 	cout << '\n';
	// }
	// rep(i, n) {
	// 	trace(a[i]);
	// }

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