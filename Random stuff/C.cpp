/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<ll, ll> umapii;
typedef unordered_map<ll, bool> umapib;
typedef unordered_map<string, ll> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, ll> mapsi;
typedef map<pair<ll, ll>, ll> mappiii;
typedef map<ll, ll> mapii;
typedef pair<ll, ll> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<ll> useti;

#define debug(x) cout << '>' << #x << ':' << x << endl;
#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll n1 = n;

		ll x = 0;
		std::vector<ll> v1;
		ll flag = 0;
		while(n1>0){
			if (n1%2==0)
			{
				flag = 1;
			}
			v1.push_back(n1%2);
			n1 = n1/2;
		}

		x = v1.size();
		ll ans = 1LL;
		if(flag){
			for (ll i = 0; i < x; ++i)
			{
				ans*=2LL;
			}
			ans--;

			cout << ans << '\n';

		}else{
			// n = n1;
	        ll maxi = 0LL;
	        for(ll i = 2; i*i <= n; i++){
	            if(n % i == 0){
	                maxi = max(maxi, i);
	                maxi = max(maxi, n / i);
	            }
	        }
	        cout<<max(maxi, 1LL)<<"\n";
		}

		
	}

	



	return 0 ; 



}

