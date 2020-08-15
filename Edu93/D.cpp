/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define all(x) (x).begin()+1, (x).end()
#define vll vector<long long>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define vvll vector<vector<ll>>
#define vset(v, n, val) v.clear(); v.resize(n, val) 

vector<vvll> dp;
vector<ll> a, b, c;

/*
DO NOT USE GREEDY. Greedy is sic
Use DP whenever you see the constraints
are favourable. Greed is not always good. 
*/

ll get(ll r, ll g, ll B){
	if((r==0 && g==0) || (B==0 && g==0) || (r==0 && B==0)) return 0;
	ll &ans = dp[r][g][B];
	if(ans!=-1) return ans;

	ans = 0ll;
	if(r>0 && g>0) ans = max(ans, get(r-1, g-1, B)+a[r]*b[g]);
	if(B>0 && g>0) ans = max(ans, get(r, g-1, B-1)+b[g]*c[B]);
	if(r>0 && B>0) ans = max(ans, get(r-1, g, B-1)+a[r]*c[B]);

	return ans;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	ll r, g, B; cin>>r>>g>>B;
	vset(a, r+1, 0);
	vset(b, g+1, 0);
	vset(c, B+1, 0); 
	rep(i, r) cin>>a[i+1];
	rep(i, g) cin>>b[i+1];
	rep(i, B) cin>>c[i+1];

	sort(all(a));
	sort(all(b));
	sort(all(c));
	dp.resize(r+1, vector<vector<ll> >(g+1, vector<ll>(B+1, -1)));
	cout << get(r,g,B) << '\n';
	
 	return 0 ; 
}

