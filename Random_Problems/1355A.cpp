#include <bits/stdc++.h>
using namespace std;
#define INF 4557430888798830399ll
typedef long long ll;
typedef pair<long long, long long> pll;

pll getMinMax(ll a){
	pll ans = {INF, -INF};
	while(a>0){
		if(ans.first>=a%10) ans.first = a%10;
		if(ans.second<=a%10) ans.second = a%10;
		a/=10;
	}
	return ans;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	ll t; cin>>t;
	while(t--){
		ll n, k; cin>>n>>k;
		pll temp = getMinMax(n);
		while(--k && temp.first>0){
			n+=temp.first*temp.second;
			temp = getMinMax(n);
		}
		cout << n << '\n';
	}
 	return 0 ; 
}

