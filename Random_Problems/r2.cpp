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


long getNumberOfOptions(vector<int> priceOfJeans, vector<int> priceOfShoes, vector<int> priceOfSkirts, vector<int> priceOfTops, int budgeted) {
	int a = priceOfJeans.size();
	int b = priceOfShoes.size();
	int c = priceOfSkirts.size();
	int d = priceOfTops.size();

	sort(priceOfJeans.begin(), priceOfJeans.end());
	sort(priceOfShoes.begin(), priceOfShoes.end());
	sort(priceOfSkirts.begin(), priceOfSkirts.end());
	sort(priceOfTops.begin(), priceOfTops.end());

	vector<int> aux1;
	vector<int> aux2;
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			aux1.push_back(priceOfJeans[i] + priceOfShoes[j]);
		}
	}
	for (int i = 0; i < c; ++i) {
		for (int j = 0; j < d; ++j) {
			aux2.push_back(priceOfSkirts[i] + priceOfTops[j]);
		}
	}

	sort(aux1.begin(), aux1.end());
	sort(aux2.begin(), aux2.end());

	long count = 0;
	int n = aux1.size();
	int m = aux2.size();

	for (int i = 0; i < n; ++i) {
		int elem = aux1[i];
		int rem = budgeted - elem;
		int ind = upper_bound(aux2.begin(), aux2.end(), elem) - aux2.begin();
		else count += ind;

	}

	return count;
}


void solve() {

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