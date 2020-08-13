
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define vset(v, n, val) v.clear(); v.resize(n, val) 
#define INF 4557430888798830399ll
#define MOD 1000000007
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define trav(a, x) for(auto& a : x)
#define fil(ar, val) memset(ar, val, sizeof(ar)) 



/*
* Let us iterate on the number of big that we take, say x 
* .....______B______B_______B.....____B
* The distance between each big is d, therefore we can place
* y = n-(d+1)*(x-1)-1 smalls in the front, choose min(y, smallSize)
* Make sure that y>=0.
* Use prefix sums to calculate the final ans
*/
int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	ll n, d, m; cin>>n>>d>>m;

	vll a(n), lo, hi, prelo, prehi;
	rep(i, n) cin>>a[i];
	rep(i, n) {
		if(a[i]>m)hi.push_back(a[i]);
		else lo.push_back(a[i]);
	}

	prelo.resize(lo.size(), 0);
	prehi.resize(hi.size(), 0);

	sort(all(lo), greater<ll>());
	sort(all(hi), greater<ll>());
	if(lo.size()>0) prelo[0] = lo[0]; 
	if(hi.size()>0) prehi[0] = hi[0];
	fr(i, 1, lo.size()-1) prelo[i] = prelo[i-1]+lo[i];
	fr(i, 1, hi.size()-1) prehi[i] = prehi[i-1]+hi[i];

	ll ans = 0;
	if(lo.size()>0)ans=prelo.back();
	rep(big, hi.size()+1){
		ll temp = 0;
		ll small = min(n-(big-1)*(d+1)-1, (ll)lo.size());
		if(small>=0){
			if(big>=1) temp+=prehi[big-1];
			if(small>=1) temp+=prelo[small-1];
		}
		ans = max(ans, temp);
	}

	cout << ans << '\n';
 	
 	return 0 ; 
}

