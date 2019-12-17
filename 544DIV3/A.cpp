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
 
	vector<ll> v1(n, 0);
	for (ll i = 0; i < n; ++i)
	{
		cin>>v1[i];
	}
 
	sort(all(v1));
 
	ll p1=0;
	ll p2 = 0;
	ll count = 0;
	ll minimum = v1[p1];
	ll ans = 0;
 
	while(p1<n && p2<n){
		if (abs(v1[p2]-v1[p1])<=5)
		{
			// debug(minimum)
			// count++;
			p2++;
			// ans = max(ans, count);
 
		}
		else
		{
			// debug(count)
			p1++;
			// p2 = p1;
			// minimum = v1[p1];
			// ans = max(ans, count);
			// count = 0;
		}
 
		ans = max(ans, p2-p1);
	}
 
	cout << ans << '\n';
	
 
 
 
	return 0 ; 
 
 
 
}