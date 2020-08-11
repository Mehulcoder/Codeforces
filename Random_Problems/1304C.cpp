#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	ll t; cin>>t;
	while(t--){
		ll n, m; cin>>n>>m;
		ll prevl = m, prevr = m, prevt = 0;
		bool ok = 1;
		rep(i, n){
			ll t, l, h; cin>>t>>l>>h;
			ll l1 = prevl-(t-prevt), r1 = prevr+(t-prevt);
			if(l1>h || r1<l) ok=0;
			prevl = max(l, l1);
			prevr = min(h, r1);
			prevt = prevt = t; 
		}
		if(ok)cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	
 	return 0 ; 
}

