#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define vll vector<long long>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define trav(a, x) for(auto& a : x)
 

const ll N=5e6+10;
vector<ll> spf, primeCount;

void precalc(){
	spf.resize(N,0);
	primeCount.resize(N, 0);
	
	spf[1] = 1;
	fr(i, 2, N-1){
		if (!spf[i])
		{
			spf[i] = i;
			for (int j = 2*i; j <= N-1; j+=i) if (!spf[j]) spf[j] = i;
		}
	}

	fr(i, 2, N-1){
		ll temp = i, count = 0;
		while(temp>1){
			count++;
			temp = temp/spf[temp];
		}
		primeCount[i] = count;
		primeCount[i]+=primeCount[i-1];
	}

	return;
}

void solve(){
	ll a, b, ans = 0; cin>>a>>b;
	ans = primeCount[a]-primeCount[b];
	cout << ans << '\n';
	return;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	precalc();
	ll t = 1;
	cin>>t;
	while(t--){
		solve();
	}
	
 	return 0 ; 
}

