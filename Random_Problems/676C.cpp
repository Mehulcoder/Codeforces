#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<long long>
#define repr(i, n) for (int i = n; i >= 0; i--)
#define vvll vector<vector<ll>>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define INF 4557430888798830399ll
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 

	ll n, k; cin>>n>>k;
	string s; cin>>s;
	vvll freq(2, vll(n, 0));
	rep(i, n) freq[s[i]-'a'][i] = 1;
	fr(i, 1, n-1){
		freq[0][i]+=freq[0][i-1]; 
		freq[1][i]+=freq[1][i-1];
	}

	ll lo = 0, hi = n, ans = 1;
	while(lo<=hi){
		ll mid = (lo+hi)/2;
		if(mid==0)break;
		bool ok = 0;
		rep(i, n-mid+1){
			ll right = i+mid-1;
			ll aCount = freq[0][right], bCount = freq[1][right];
			if(i>0) aCount-=freq[0][i-1], bCount-=freq[1][i-1];
			if(min(aCount, bCount)<=k){
				ok = 1, ans = max(ans, mid);
				break;
			}
		}
		if(ok)lo = mid+1;
		else hi = mid-1;
	}

	cout << ans << '\n';
 	
 	return 0 ; 
}

