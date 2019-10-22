#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

typedef long long li;
typedef unsigned long long uli;
typedef pair<int, int> pii;
typedef long double ld;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forb(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define vi vector<int>
#define x first
#define y second

const int INF = 2e9;
const li INF64 = 1e18;
const int M = 2 * 1000 * 1000;
const int N = 300 * 1000 + 100;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = 3.14159265359;

pair<pii, pii> intersect(pii a, pii b, pii c, pii d) {
	int lf, rg, up, dn;
	lf = max(min(a.x, b.x), min(c.x, d.x));
	rg = min(max(a.x, b.x), max(c.x, d.x));
	up = min(max(a.y, b.y), max(c.y, d.y));
	dn = max(min(a.y, b.y), min(c.y, d.y));

	if (rg <= lf || up <= dn) return { {0, 0}, {0, 0} };

	return { { lf, dn }, { rg, up } };
}

li square(pii a, pii b) {
	return 1ll * abs(a.x - b.x) * abs(a.y - b.y);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<pii> p(6);

	forn(i, 6)
		cin >> p[i].x >> p[i].y;

	pair<pii, pii> wb1 = intersect(p[0], p[1], p[2], p[3]);
	pair<pii, pii> wb2 = intersect(p[0], p[1], p[4], p[5]);
	pair<pii, pii> inter = intersect(wb1.x, wb1.y, wb2.x, wb2.y);

	li swhite = square(p[0], p[1]);
	li swb1 = square(wb1.x, wb1.y);
	li swb2 = square(wb2.x, wb2.y);
	li sinter = square(inter.x, inter.y);

	if (swhite > swb1 + swb2 - sinter) cout << "YES\n";
	else cout << "NO\n";
}