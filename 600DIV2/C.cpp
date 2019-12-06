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
	

	ll n, m;
	cin>>n>>m;

	vector<ll> v1(n, 0);
	vector<ll> sum(n, 0);
	for (ll i = 0; i < n; ++i)
	{
		cin>>v1[i];

		
	}

	sort(v1.begin(), v1.end());

	for (ll i = 0; i < n; ++i)
	{
		if (i!=0)
		{
			sum[i] = sum[i-1]+v1[i];
		}else{
			sum[i] = v1[i];
		}
	}

	// for (ll i = 0; i < n; ++i)
	// {
	// 	cout << sum[i] << ' ';
	// }
	
	vector<ll> x(200001, 0);
	for (ll i = 0; i < n; ++i)
	{
		if (i-m+1>0)
		{
			// debug(i-m+1)
			// debug(x[i-m+1])
			x[i] = sum[i] + x[i-m];
		}else{
			x[i] = sum[i];
		}

		cout << x[i]<< ' ';
		
	}

	cout << '\n';



	return 0 ; 



}

