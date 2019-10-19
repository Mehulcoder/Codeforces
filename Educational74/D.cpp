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
	
	ll n;
	cin>>n;

	string s;
	cin>>s;

	ll ans = ((n)*(n-1))/2;
	ll subtract = 0;

	for (ll i = 0; i < n; ++i)
	{
		ll count = 0;
		if (s[i] == 'A' && i+1<n && s[i+1] == 'B')
		{
			i++;
			while(i<n && s[i]=='B'){
				count++;
				i++;
			}
			i--;
		}
		subtract+=count;
	}

	//cout << "1- "<<subtract << '\n';


	for (ll i = 0; i < n; ++i)
	{
		ll count = 0;
		if (s[i] == 'B' && i+1<n && s[i+1] == 'A')
		{
			i++;
			while(i<n && s[i]=='A')
			{
				//cout << "HERE" << '\n';
				count++;
				i++;
			}
			i--;
		}
		subtract+=count;
	}

	//cout << "2- "<<subtract << '\n';
	


	for (ll i = n-1; i >= 0; --i)
	{
		ll count = 0;
		if (s[i] == 'B' && i-1>=0 && s[i-1] == 'A')
		{
			//cout << i <<"here"<< '\n';
			i--;
			while(i>=0 && s[i]=='A'){
				count++;
				i--;
			}
			i++;
		}
		subtract+=count;
		//cout << subtract << '\n';
	}

	//cout << "3- "<<subtract << '\n';


	for (ll i = n-1; i >= 0; --i)
	{
		ll count = 0;
		if (s[i] == 'A'&& i-1>=0 && s[i-1] == 'B')
		{
			i--;
			while(i>=0 && s[i]=='B'){
				count++;
				i--;
			}
			i++;
		}
		subtract+=count;
	}

	//cout << "4- "<<subtract << '\n';

	ll ab = 0;
	for (ll i = 0; i < n; ++i)
	{
	//	ll ab = 0
		if (s[i]=='A' && i+1<n && s[i+1]=='B')
		{
			ab++;
		}
	}

	//cout << "AB- "<<ab << '\n';
	//cout << subtract << '\n';

	ll ba = 0;
	for (ll i = 0; i < n; ++i)
	{
	//	ll ab = 0
		if (s[i]=='B' && i+1<n && s[i+1]=='A')
		{
			ba++;
		}
	}

	//cout << "BA- "<<ba << '\n';

	cout << ans-subtract+ab+ba << '\n';


	return 0 ; 



}
