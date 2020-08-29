/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 4557430888798830399ll
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
ll n, l[123456], r[123456], a[123456];

/*
Nice question:
* Basically you need to know ki uske left waala kab gaya
* yaa uske right waala kab gaya. Dono me so jo pehle jaega
* uske just baad ye chala jaega(add one operation). Yaa fir
* ho sakta hai ye hi pehle chala jaye (check height).
* Take min of (heighti, lefti, righti)
*/

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	cin >> n;
	fr(i, 1, n) cin >> a[i];

	fr(i, 1, n) l[i] = min(l[i - 1] + 1 , a[i]);
	frr(i, n, 1) r[i] = min(r[i + 1] + 1 , a[i]);

	ll ans = 1;
	fr(i, 1, n) ans = max(ans , min(l[i], r[i]));

	cout << ans;

	return 0 ;
}