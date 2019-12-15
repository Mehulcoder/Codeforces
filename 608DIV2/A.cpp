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
	t=1;

	while(t--){
		ll a, b, c, d, e, f;
		cin>>a>>b>>c>>d>>e>>f;

		ll ans = 0;

		ll temp = min(b, min(c, d));
		ll temp2 = min(a, d);

		if (f>e)
		{
			ans += f*temp;
			d-=temp;

			ans+=e*min(d, a);
		}else{
			ans += e*temp2;
			d-=temp2;

			ans+=f*min(b, min(c, d));
		}

		cout << ans << '\n';



	}



	return 0 ; 



}

