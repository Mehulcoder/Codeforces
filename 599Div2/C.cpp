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
	ll n2 = n;
	ll isprime = 1;
	ll factors = 0;
	ll ispower = 0;
	if(n==1)
    {
        cout<<"1"<<endl;
        return 0;
    }
	for (ll i = 2; i*i <= n; ++i)
	{
		if (n%i==0)
		{
			//DEBUG(i)

			if (factors!=0)
			{
				cout << 1 << '\n';
				return 0;
			}
		

		isprime = 0;
		factors = i;
		while(n%i==0)
            n=n/i;
    	}
	}


	if (isprime)
	{
		cout << n2 << '\n';
	}else{
		if (n==1)
		{
			cout << factors << '\n';
		}else{
			cout << 1 << '\n';
		}
	}

	



	return 0 ; 



}

