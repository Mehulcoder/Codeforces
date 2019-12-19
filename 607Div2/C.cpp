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
	
	ll  t;
	cin>>t;
	while(t--){
		ll x;
		cin>>x;

		string s;
		cin>>s;
		ll l  = 1;

		ll ans = 0;

		while(1){
			if (s.size()>=x)
			{
				break;
			}

			string t = s.substr(l);
			for (ll i = 0; i < s[l-1]-'0'-1; ++i)
			{
				// debug(s)
				// debug(s.substr(l))
				s+=t;
			}
			l++;
		}

		 // cout << s << '\n';
		// cout << l << '\n';
		ans = s.size();
		// debug(ans)	
		ll m = s.size();
		while(l<=x){
			ans=(ans+((s[l-1]-'0'-1+MOD)%MOD)*((ans-l+MOD)%MOD))%MOD;
			// debug(ans)
			l++;
		}

		cout << ans << '\n';
	}
	
	



	return 0 ; 



}

