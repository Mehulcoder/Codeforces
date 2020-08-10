#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(x) (x).begin(), (x).end()
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

int main( int argc , char ** argv )
{
	ll n; cin>>n;
	vll v(n);
	rep(i, n) cin>>v[i];
	ll ind = max_element(all(v))-v.begin(), ans = v[ind];
	rep(i, n){
		ll temp = v[i], mini = v[i];
		fr(j, i+1, n-1) mini = min(mini, v[j]),temp+=mini;
		mini = v[i];
		frr(j, i-1, 0)mini = min(mini, v[j]), temp+=mini;
		if(ans<temp) ind = i, ans = temp;
	}

	ll mini = v[ind];
	fr(j, ind+1, n-1)mini = min(mini, v[j]), v[j]=mini;
	mini = v[ind];
	frr(j, ind-1, 0)mini = min(mini, v[j]), v[j]=mini;
	rep(i, v.size()) cout << v[i] << ' ';
	cout <<'\n';
 	return 0 ; 
}




	