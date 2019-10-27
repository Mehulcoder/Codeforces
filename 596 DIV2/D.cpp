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
	
	ll n,k;
	cin>>n>>k;
	map<vector<pii>, ll> m1;

	vector<ll> input(n, 0);
	for (ll i = 0; i < n; ++i)
	{
		cin>>input[i];
	}	

	ll result = 0;
	
	for (ll i = 0; i < n; ++i)
	{
		vector<pii> temp2;	
		vector<pii> temp;
		ll count = 0;

		while(input[i]%2==0){
			count++;
			input[i] = input[i]/2;
		}
		
		if (count%k!=0)
		{

			temp2.push_back({2, count%k});
			temp.push_back({2, k-count%k});
		}

		for (ll j = 3; j <= sqrt(input[i]); j=j+2)
		{
			
			
			ll oddcount = 0;
			while(input[i]%j==0){
				oddcount++;
				input[i] = input[i]/j;
			}

			if (oddcount%k!=0)
			{
				temp2.push_back({j, oddcount%k});
				temp.push_back({j, k-oddcount%k});
			}


		}

		if (input[i]>2)
		{	
			temp2.push_back({input[i], 1%k});
			temp.push_back({input[i], k-1%k});	
		}
		
		sort(temp2.begin(), temp2.end());
		sort(temp.begin(), temp.end());

		if (m1[temp]>0)
		{
			result = result+m1[temp];
		}
		
		m1[temp2]++;

	}

	cout<<result<<endl;

	return 0 ; 



}
