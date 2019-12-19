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
	vector<ll> positive;
	vector<ll> negative;


	for (ll i = 0; i < m; ++i)
	{
		ll a, b, c;
		cin>>a>>b>>c;
		v1[a-1]+=c;
		v1[b-1]-=c;	// v1[i]+=a;
	}

	for (ll i = 0; i < n; ++i)
	{
		if (v1[i]>0)
		{
			positive.push_back(i);
		}else if (v1[i]<0)
		{
			negative.push_back(i);
		}
	}

	// for (ll i = 0; i < positive.size(); ++i)
	// {
	// 	cout << positive[i] << '\n';
	// }
	// // debug(v1[negative[0]])
	

	ll pos_start = 0;
	ll neg_start = 0;
	vector<tuple<ll, ll, ll> > ans;
	while(pos_start<positive.size() && neg_start<negative.size()){
		// cout << "here" << '\n';
		while(v1[positive[pos_start]]>0 && neg_start<negative.size()){
			if (v1[negative[neg_start]]==0)
			{
				neg_start++;
				continue;
			}
			ll k = min(v1[positive[pos_start]], abs(v1[negative[neg_start]]));
			v1[positive[pos_start]] -= k;
			v1[negative[neg_start]] += k;
			ans.push_back({positive[pos_start], negative[neg_start], k});
		}
		pos_start++;
	}

	cout << ans.size() << '\n';

	for(ll i=0;i<ans.size();i++)
    {
        cout<<get<0>(ans[i])+1<<" "<<get<1>(ans[i])+1<<" "<<get<2>(ans[i])<<endl;
    }

	return 0 ; 



}

