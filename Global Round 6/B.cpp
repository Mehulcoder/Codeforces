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
		ll xi;
		cin>>xi;
		ll flag = 0;

		// if (xi==14)
		// {
		// 	cout<<"YES"<<endl;
		// 	continue;
		// }

		for (ll i = 1; i <= 6; ++i)
		{
			ll x = xi;
			ll b = 21-i;
			x-=b;

			if (x%14==0 && x>=0)
			{
				flag = 1;
				break;
			}

		}

		if (flag==1)
		{
			cout << "YES" << '\n';
		}else{
			cout << "NO" << '\n';
		}
	}
	



	return 0 ; 



}

