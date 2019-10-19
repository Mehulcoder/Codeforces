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
	
	ll n, k;
	cin>>n>>k;

	vector<ll> arr1(n, 0);
	for (ll i = 0; i < n; ++i)
	{
		cin>>arr1[i];
	}

	sort(arr1.begin(), arr1.end());

	vector<pii> arrfreq;

	ll value0 = arr1[0];
	arrfreq.push_back({value0, 1});
	ll current = 0;

	for (ll i = 1; i < n; ++i)
	{
	 	if (arr1[i] == arr1[current])
	 	{
	 		arrfreq[current].second++;
	 	}else{
	 		arrfreq.push_back({arr1[i], 1});
	 		current++;
	 	}
	}

	// for (ll i = 0; i < arrfreq.size(); ++i)
	// {
	// 	cout << arrfreq[i].first<<" "<<arrfreq[i].second << '\n';
	// }

	ll l = 0;
	ll r = arrfreq.size()-1;

	ll diff = arrfreq[r].first - arrfreq[l].first;

	while(l<r && k>0){
		if (arrfreq[l].second<=arrfreq[r].second)
		{
			ll kreq = (arrfreq[l+1].first-arrfreq[l].first)*(arrfreq[l].second);
		//	cout << arrfreq[l].second<<" "<<arrfreq[r].second << '\n';

			//cout << k<<" "<<kreq << '\n';
			if (kreq<=k)
			{
				arrfreq[l+1].second += arrfreq[l].second;
				k = k-kreq;
				l++;
			}else{

				ll dec = k/arrfreq[l].second;

				arrfreq[l].first = arrfreq[l].first+dec;
				diff = arrfreq[r].first - arrfreq[l].first;
				break;
				//return 0;
			}

		}else{

			ll kreq = (arrfreq[r].first-arrfreq[r-1].first)*(arrfreq[r].second);
			if (kreq<=k)
			{
				arrfreq[r-1].second += arrfreq[r].second;
				k = k-kreq;
				r--;
			}else{
				ll dec = k/arrfreq[r].second;

				arrfreq[r].first = arrfreq[r].first-dec;
				diff = arrfreq[r].first - arrfreq[l].first;
				break;
			}
		}

	}

	diff = arrfreq[r].first - arrfreq[l].first;
	cout << diff << '\n';

	return 0 ; 



}
