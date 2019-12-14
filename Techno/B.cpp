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

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
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

		vector<ll> v1(n, 0);
		for (ll i = 0; i < n; ++i)
		{
			cin>>v1[i];
		}

		//sort(all(v1));
		vector<ll> v2(n, 0);
		unordered_map<ll, ll> m1;

		for (ll i = 0; i < n; ++i)
		{
			ll a = v1[i];
			// ll start = 1;
			ll count = 0;
			while(1){
				if (a%2==0)
				{
					count++;
					// DEBUG(start)
					a = (a/2);
					// DEBUG(a)

				}else{
					break;
				}
			}

			m1[a] = max(m1[a], count);
			v2[i] = a;	
		}

		ll ans = 0;
		for(auto elem : m1){
			ans+=elem.second;
		}
		cout << ans << '\n';
		// sort(all(v2));


	}

	



	return 0 ; 



}

