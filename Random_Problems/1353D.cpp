#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;
#define f first
#define s second
#define vll vector<long long>
#define vset(v, n, val) v.clear(); v.resize(n, val) 
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	ll t = 1;
	cin>>t;
	while(t--){
		ll n; cin>>n;
		vll v(n, 0);
		multiset<pair<ll, pll>> m1;
		m1.insert({-n, {0, n-1}});
		rep(i, n){
			auto top = *m1.begin();
			m1.erase(m1.begin());
			ll mid = (top.s.f+top.s.s)/2, left = top.s.f, right=top.s.s;
			v[mid] = i+1;
			m1.insert({-mid+left, {left, mid-1}});
			m1.insert({-right+mid, {mid+1, right}});
		}

		rep(i, n) cout << v[i] << ' ';
		cout <<'\n';
	}
	
 	return 0 ; 
}

