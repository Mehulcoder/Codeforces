/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)


ll prodIfEven(vll &A, ll n, ll k) {
	ll i = 0, j = n - 1;
	ll count = 0;
	ll prod = 1;
	while (count < k) {
		ll left = A[i] * A[i + 1];
		ll right = A[j] * A[j - 1];
		if (left > right) {
			prod *= left;
			count += 2;
			i += 2;
		} else {
			prod *= right;
			count += 2;
			j -= 2;
		}
	}

	return prod;
}

ll maxProd(vector<ll> &A, ll n, ll k) {
	assert(n >= k);
	sort(all(A));

	if (!(k % 2)) return prodIfEven(A, k, n);
	else {
		ll prod = 1;
		int i = 0, j = n - 1;

		//Max element is 0
		if (A.back() == 0) {
			return 0;
		}

		//Max element is neg
		if (A.back() < 0) {
			rep(i, k) {
				prod *= A[n - i - 1];
			}
			return prod;
		}

		//Max element is pos;
		prod *= A.back();
		return prod * prodIfEven(A, n - 1, k - 1);
	}
}


void solve() {
	ll n; cin >> n;
	vll a(n);

	rep(i, n) {
		cin >> a[i];
	}

	cout << maxProd(a, n, 5) << '\n';
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