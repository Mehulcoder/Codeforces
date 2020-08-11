
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define trav(a, x) for(auto& a : x)

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	string s; cin>>s;
	map<string, ll> m2;
	map<char, ll> m1;

	rep(i, s.size()){
		trav(cnt, m1) m2[cnt.first+s.substr(i, 1)]+=cnt.second;
		m1[s[i]]++;
	}
	
	ll ans = 0ll;
	trav(elem, m2)ans = max(ans, elem.second);
	trav(elem, m1)ans = max(ans, elem.second);
	cout << ans << '\n';
	
 	return 0 ; 
}

