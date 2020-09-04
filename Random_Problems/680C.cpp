/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vll vector<long long>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

vector<ll> spf;
vll primes;
const ll N = 101;
void precalc() {
	spf.resize(N, 0);

	//Calculating spf
	spf[1] = 1;
	fr(i, 2, N - 1) {
		if (!spf[i]) {
			spf[i] = i;
			for (int j = 2 * i; j <= N - 1; j += i) {
				if (!spf[j]) {
					spf[j] = i;
				}
			}
		}
	}

	fr(i, 2, N - 1) {
		if (spf[i] == i) primes.push_back(i);
	}
	return;
}

int main(int argc , char ** argv) {
	precalc();
	rep(i, 4) {
		ll currPrime = primes[i];
		cout << currPrime << endl;
		fflush(stdout);

		string out; cin >> out;
		if (out == "no") continue;

		fr(j, i, primes.size() - 1) {
			if (currPrime * primes[j] > 100) {
				cout << "prime" << endl;
				return 0;
			};
			cout << currPrime*primes[j] << '\n';
			fflush(stdout);

			string out2; cin >> out2;
			if (out2 == "yes") {
				cout << "composite" << '\n';
				return 0;
			}
		}
	}
	cout << "prime" << endl;
	return 0 ;
}