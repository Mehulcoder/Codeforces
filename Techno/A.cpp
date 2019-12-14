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

		ll digits = 0;
		ll start = 1;

		for (ll i = 0; i < 11; ++i)
		{
			if (n/start==0)
			{
				digits = i;
				break;
			}
			start=start*10;
		}

		// cout << digits << '\n';
		ll ans = (digits-1)*9;
		ll add = n/(pow(10, digits-1));
		// cout << add << '\n';

		ans+=add-1;
		
		
		
		ll temp = 0;
		for (ll i = 0; i < digits; ++i)
		{
			temp+=pow(10, i)*add;
		}
		
		if (temp<=n)
		{
			ans++;
		}

		cout << ans << '\n';
	}
	



	return 0 ; 



}

