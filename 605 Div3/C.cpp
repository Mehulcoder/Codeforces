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
	

	ll n,k;
	cin>>n>>k;

	string s;
	cin>>s;

	set<char> s1;
	for (ll i = 0; i < k; ++i)
	{
		char a;
		cin>>a;

		s1.insert(a);
	}

	ll count = 0;
	ll ans = 0;
	for (ll i = 0; i < s.size(); ++i)
	{
		if (s1.find(s[i])==s1.end())
		{
			// DEBUG(count)
			ans += (count*(count+1))/2;
			count = 0;
		}else{
			count++;
			if (i==s.size()-1)
			{
				ans+=(count*(count+1))/2;
			}
		}
	}


	cout << ans << '\n';



	return 0 ; 



}

