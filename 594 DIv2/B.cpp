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

	vector<ll> sticks(n, 0);
	for (ll i = 0; i < n; ++i)
	{
		cin>>sticks[i];
	}

	sort(sticks.begin(), sticks.end());
	ll start = 0;
	ll end = n-1;

	ll ans = 0;
	ll x, y;
	x=0;
	y=0;
	while(start<=end){
		if (start==end)
		{
			x+=sticks[start];
			break;
		}
		y+=sticks[start];
		x+=sticks[end];
		start++;
		end--;
	}



	cout << x*x+y*y << '\n';


	return 0 ; 



}
