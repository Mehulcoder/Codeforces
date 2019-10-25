/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

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

class myComparator
{
public:
	bool operator()(pii a, pii b){
		if (a.s == b.s)
		{
			return (a.f>b.f);
		}
		
		return (a.s<b.s);
	}
};

bool mysort(pii a, pii b){
	if (a.f==b.f)
	{
		return (a.s>b.s);
	}

	return a.f<b.f;
}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	ll t;
	cin>>t;

	while(t--)
	{
		ll n;
		cin>>n;

		vector<pii> voters(n, {0, 0});

		for (ll i = 0; i < n; ++i)
		{
			ll a, b;
			cin>>a>>b;
			voters[i] = {a, b};
		}

		sort(voters.begin(), voters.end(), mysort);
		//reverse(voters.begin(), voters.end());

		ll totalvotes = 0;
		ll totalcost = 0;

		multiset<pii, myComparator> myset;

		for (ll i = n-1; i >= 0; --i)
		{
			myset.insert(voters[i]);

			//ll requiredvotes = voters[i].f- totalvotes;
		
			if (voters[i].f-i>totalvotes)
			{
				pii cheapest = *myset.begin();

				totalcost+=cheapest.s;
				totalvotes++;
				myset.erase(cheapest);

			}

		}

		cout << totalcost << '\n';

	}


	return 0 ; 



}
