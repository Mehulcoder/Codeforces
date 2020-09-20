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



void solve() {
	int n, a, b; cin >> n >> a >> b;

	vll p(n);
	queue<ll> toCheckForB;
	map<ll, ll> m;
	rep(i, n) {
		cin >> p[i];
		m[p[i]] = 1;  //Assume initially all of them are in first set
	}

	rep(i, n) {
		if (m.find(a - p[i]) == m.end()) {
			toCheckForB.push(p[i]); //These can only be a part of B and never A
		}
	}

	while (!toCheckForB.empty()) {
		ll toCheck = toCheckForB.front();
		toCheckForB.pop();

		m[toCheck] = 2;
		if (m.find(b - toCheck) == m.end()) { //If it can't be even a part of B
			cout << "NO" << '\n';
			return;
		}

		if (m[b - toCheck] == 2) continue; //We have already checked its partner

		//Its partner was a member of set A before put it to B (or it hasn't been checked yet)
		m[b - toCheck] = 2;

		//This member might have had a partner in A, now that partner could no more
		//be in A as it has lost a-partner (i.e b-toCheck), since elements are unique
		//the partner has only one option to come to B.

		if (m.find(a - (b - toCheck)) != m.end()) {
			toCheckForB.push(a - b + toCheck);  //Check if it is even possible to put it in B
		}
	}

	cout << "YES" << '\n';
	rep(i, n) {
		cout << m[p[i]] - 1 << ' ';
	}
	cout << '\n';
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