
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

void solve() {
	ll n, k; cin >> n >> k;
	string s; cin >> s;
	s += s;
	n *= 2;


	ll pos = n;
	ll ind = 0;
	fr(i, 1, n - 1) {
		if (s[i] > s[ind]) {
			pos = i;
			break;
		} else if (s[i] == s[ind]) {
			ll q = i;
			ll p = ind;
			while (p < i - 1 && s[p] == s[q]) {
				p++;
				q++;
			}
			if (s[p] < s[q]) {
				pos = i;
				break;
			}
		}
	}
	string ans = s.substr(0, pos);
	while (ans.size() < k) {
		ans += s.substr(0, pos);
	}

	ans = ans.substr(0, k);
	cout << ans << endl;
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