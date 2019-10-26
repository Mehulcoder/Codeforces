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
		ll n, k, d;
		cin>>n>>k>>d;

		vector<ll> channels(n, 0);
		//vector<ll> channelcount(n, 0);
		for (ll i = 0; i < n; ++i)
		{
			cin>>channels[i];
		}

		ll ans = INT_MAX;

		ll start = 0;
		unordered_map<ll, ll> m1;
		set<ll> myset;

		for (ll i = 0; i < d; ++i)
		{
			m1[channels[i]]++;
			myset.insert(channels[i]);
		}

		ans = myset.size();

		for (ll i = d; i < n; ++i)
		{
			ll temp = 0;
			
			m1[channels[start]]--;
			if (m1[channels[start]]<=0)
			{
				myset.erase(channels[start]);
			}
			
			m1[channels[i]]++;
			myset.insert(channels[i]);

			start++;

			temp = myset.size();
			
			ans = min(ans, temp);

		}

		cout << ans << '\n';

		

	}


	return 0 ; 



}
