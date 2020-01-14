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
		ll a, b;
		cin>>a>>b;

		ll maxdigit = 0;
		ll tempb = b;
		while(tempb>0){
			tempb = tempb/10;
			maxdigit++;
		}

		ll start = pow(10, maxdigit)-1;
		if (start>b)
		{
			maxdigit--;
			start = pow(10, maxdigit)-1;
		}

		ll ans = 0;
		while(start>0){
			ans+=a;
			maxdigit--;
			start = pow(10, maxdigit)-1;
		}

		cout << ans << endl;
	}
	



	return 0 ; 



}

