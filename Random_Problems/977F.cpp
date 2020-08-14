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
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define trav(a, x) for(auto& a : x)
#define fil(ar, val) memset(ar, val, sizeof(ar)) 
const ll MOD = 1e9+9;
 
 
/*
* Iterate from start and keep on storing the pair,
* {ending at, maxSizeTill}. Use this value of the 
* last index, to generate the ans
*/ 

vll v;
map<ll, pll> m;
void solve(){
	ll n; cin>>n;
	m.clear();
	vset(v, n, 0);	
	
	rep(i, n) cin>>v[i];
	pll ans0;
	
	rep(i, n){
		if(m.find(v[i]-1)==m.end()){
			m[v[i]] = {v[i], 1};
		}else{
			auto temp = m[v[i]-1];
			temp.f = v[i], temp.s++;
			m[v[i]] = temp;
		}
		ans0 = ((ans0.s<=m[v[i]].s)?(m[v[i]]):(ans0));
	}
	
	vll ans;
	ll end = ans0.f, len = ans0.s;
	while(len--) ans.push_back(end--);
	reverse(all(ans));

	vll indices(ans.size(), -1);
	ll curr = 0;
	rep(i, ans.size()){
		while(v[curr]!=ans[i]) curr++;
		indices[i]=curr;
	}

	cout << indices.size() << '\n';
	rep(i, indices.size()) cout << indices[i]+1 << ' ';
	cout <<  '\n';
	return;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	ll t = 1;
	while(t--){
		solve();
	}
 	return 0 ; 
}

