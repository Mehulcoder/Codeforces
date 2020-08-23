/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 4557430888798830399ll
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
/*
* The value of A can be at max 2*a-1.
* Otherwise we would choose to keep the value of A
* as 1 (which would obviously divide any B and C)

* Now the highest value of a could be 2*a which means
* to make b equal to A wel'll need max(abs(2*a-b), abs(b-1))
* operations which are less than max(a, b-1) ~ b.
* So b will be at max 2*b

* Choose the closest value of C. Which is easy.
*/

void solve() {
	ll a, b, c;
	cin >> a >> b >> c;
	ll af = a, bf = b, cf = c;

	ll diffFinal = INF;
	fr(A, 1, 2 * a) {
		for (int B = A; B <= 2 * b; B += A) {
			ll diff = abs(a - A) + abs(b - B);
			ll c1 = (c / B) * B + B;
			ll c2 = (c / B) * B;
			if (abs(c1 - c) < abs(c2 - c)) {
				diff += abs(c1 - c);
				if (diffFinal >= diff) {
					diffFinal = diff;
					af = A;
					bf = B;
					cf = c1;
				}
			} else {
				diff += abs(c2 - c);
				if (diffFinal >= diff) {
					diffFinal = diff;
					af = A;
					bf = B;
					cf = c2;
				}
			}
		}
	}


	cout << diffFinal << '\n';
	cout << af << ' ' << bf << " " << cf << endl;
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