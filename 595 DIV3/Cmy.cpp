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
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007

int arr[39];

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	
	int q;
	cin>>q;

	while(q--){
		for (int i = 0; i < 39; ++i)
		{
			arr[i] = 0;
		}
		ll n;
		cin>>n;

		ll start = 0;
		int rem;
		while(n>0){
			rem = n%3;
			arr[start] = rem;
			start++;
			n = n/3;
		}

		// for (int i = 0; i < 39; ++i)
		// {
		// 	cout<<arr[i];
		// }
		// cout << '\n';


		int two = -1;
		for (int i = 0; i < 39; ++i)
		{
			if (arr[i] == 2)
			{
				two = i;
			}
		}
		if (two == -1)
		{
			ll ans = 0;
			ll f = 1;
			for (ll i = 0; i < 39; ++i)
			{
				ans+=arr[i]*f;
				f=f*3;
			}
			cout << ans << '\n';
			continue;
		}

		int zero = -1;
		for (int i = two; i < 39; ++i)
		{
			if (arr[i]==0)
			{
				zero = i;
				break;
			}
		}

		arr[zero] = 1;
		for (int i = 0; i < zero; ++i)
		{
			arr[i] = 0;
		}

		ll ans = 0;
		ll f = 1;
		for (ll i = 0; i < 39; ++i)
		{
			ans+=arr[i]*f;
			f=f*3;
		}
		
		// for (int i = 0; i < 39; ++i)
		// {
		// 	cout<<arr[i];
		// }
		//  cout << '\n';
		cout<<ans<<endl;
	}



	return 0 ; 



}
