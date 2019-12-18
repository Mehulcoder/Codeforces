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
	

	ll n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;

		ll zero = 0;
		ll sum = 0;
		for (ll i = 0; i < s.size(); ++i)
		{
			sum+=s[i]-'0';
			if (s[i]=='0')
			{
				zero++;
			}
		}

		if (sum%3!=0)
		{
			cout << "cyan" << '\n';
			continue;
		}

		if (zero==0)
		{
			cout<<"cyan"<<endl;
			continue;
		}

		ll even = 0;
		if (zero==1)
		{
			for (ll i = 0; i < s.size(); ++i)
			{
				if ((s[i]-'0')%2==0 && s[i]!='0')
				{
					even++;
					break;	
				}
			}

			if (even!=0)
			{
				cout << "red" << '\n';
				continue;
			}else{
				cout << "cyan" << '\n';
				continue;
			}
		}

		if (zero>=2)
		{
			cout << "red" << '\n';
		}




	}



	return 0 ; 



}

	