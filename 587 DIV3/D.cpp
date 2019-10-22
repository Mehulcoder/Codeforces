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

ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
  
// Function to find gcd of array of 
// numbers 
ll findGCD(vector<ll> arr, ll n) 
{ 
    ll result = arr[0]; 
    for (ll i = 1; i < n; i++) 
        result = gcd(arr[i], result); 
  
    return result; 
} 

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	ll n;
	cin>>n;

	vector<ll> arr(n);
	for (ll i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	sort(arr.begin(), arr.end());

	vector<ll> diffarr(n);
	for (ll i = 0; i < n; ++i)
	{
		diffarr[i] = arr[n-1]-arr[i];
	}

	ll hcf = findGCD(diffarr, n);

	ll y = 0;
	ll z = hcf;
	
	for (ll i = 0; i < n; ++i)
	{
		y+=diffarr[i]/hcf;
	}

	cout << y<<" "<<z << '\n';
	return 0 ; 



}
