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
	cin>>t;

	while(t--){
		ll n;
		cin>>n;

		vector<ll> left(n, 0);
		vector<ll> right(n, 0);
		ll one = 0;
		ll two = 0;
		for (ll i = 0; i < n; ++i)
		{
			cin>>left[i];
			if (left[i]==1)
			{
				one++;
			}else{
				two++;
			}
		}

		for (ll i = 0; i < n; ++i)
		{
			cin>>right[i];
			if (right[i]==1)
			{
				one++;
			}else{
				two++;
			}
		}

		ll temp = 0;
		set<ll> s1;
		unordered_map<ll, ll>rightindices;

		for (ll i = 0; i < n; ++i)
		{
			if (right[i]==2)
			{
				temp--;
				right[i] = temp;
			}else{
				temp++;
				right[i] = temp;
			}

			if (s1.find(temp)==s1.end())
			{
				s1.insert(temp);
				rightindices[temp] = i;
			}
		}

		 temp = 0;
		for (ll i = n-1; i >= 0; --i)
		{
			if (left[i]==2)
			{
				temp--;
				left[i] = temp;
			}else{
				temp++;
				left[i] = temp;
				// leftindices[temp]
			}
		}

		ll diff = one-two;
		// debug(diff)
		if (diff == 0)
		{
			cout << 0 << '\n';
			continue;
		}

		ll ans = 2*n;
		for (ll i = n-1; i >= 0; --i)
		{
			ll temp2 = diff-left[i];
			ll index = INT_MAX;
			if (s1.find(temp2)!=s1.end())
			{
				index = rightindices[temp2];
			}

			// debug(index)
			// debug(n-i+index+1)

			ans = min(ans, n-i+index+1);
		}

		// only right
		if (s1.find(diff)!=s1.end())
		{
			ans = min(ans, rightindices[diff]+1);
		}

		for (ll i = n-1; i >= 0; --i)
		{
			if (left[i]==diff)
			{
				ans = min(ans, n-i);
			}
		}

		cout << ans << '\n';





	}
	



	return 0 ; 



}

