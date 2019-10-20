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
	
	ll a,b,c,d;
	cin>>a>>b>>c>>d;

	if (a+b == c+d)
	{
		cout << "YES" << '\n';
		return 0;
	}
	if (a+c == b+d)
	{
		cout << "YES" << '\n';
		return 0;
	}

	if (a+d == b+c)
	{
		cout << "YES" << '\n';
		return 0;
	}

	if (a == b+c+d)
	{
		cout << "YES" << '\n';
		return 0;
	}

	if (a+b+c == d)
	{
		cout << "YES" << '\n';
		return 0;
	}

	if (a+b+d == c)
	{
		cout << "YES" << '\n';
		return 0;
	}

	if (a+c+d == b)
	{
		cout << "YES" << '\n';
		return 0;
	}

	cout << "NO" << '\n';

	return 0 ; 



}
