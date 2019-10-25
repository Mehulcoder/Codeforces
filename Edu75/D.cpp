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

bool mysort(pii a, pii b)
{
	if (a.f==b.f)
	{
		return a.s<b.s;
	}else{	
		return (a.f<b.f);
	}
}

bool check(vector<pii> range, ll mid, ll s){
	ll n = range.size();
	ll rightcount = 0;
	ll leftcount = 0;
	ll sum = 0;

	for (ll i = n-1; i >= 0; --i)
	{
		if (range[i].s>=mid && rightcount<(n/2)+1)
		{
			sum+=max(range[i].f, mid);
			rightcount++;
		}else
		{
			sum+=range[i].f;
			leftcount++;
		}
	}

	if (rightcount!=(n/2)+1 || sum>s)
	{
		return 0;
	}

	return 1;

}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	ll t;
	cin>>t;

	while(t--){
		ll n, s;
		cin>>n>>s;

		vector<pii> range(n, {0,0});
		ll maximum = INT_MIN;

		for (ll i = 0; i < n; ++i)
		{
			ll a, b;
			cin>>a>>b;

			maximum = max(maximum, max(a,b));

			range[i] = {a, b};
		}

		sort(range.begin(), range.end(), mysort);

		ll start = 0;
		ll end = maximum+1;
		ll ans = 0;

		while(start<=end){
			ll mid = (start+end)/2;
			//cout << mid << '\n';
			if (check(range, mid, s))
			{
			//cout << "Mid"<<" "<<mid << '\n';				
				start = mid+1;
				//cout << start<<" "<<mid<<" "<<end << '\n';
				ans = mid;
			}else{
				end = mid-1;
			}

		}

		cout << ans << '\n';

	}


	return 0 ; 



}
