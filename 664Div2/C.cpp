/*

                Name: Mehul Chaturvedi
                IIT-Guwahati

*/

/*
		Talent is Overrated
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define vll vector<long long>
#define vvll vector<vector<ll>>
#define vset(v, n, val) v.clear(); v.resize(n, val) 
#define INF 4557430888798830399ll
#define MOD 1000000007
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define trav(a, x) for(auto& a : x)
#define fil(ar, val) memset(ar, val, sizeof(ar)) 


/*
* Very few numbers a possible, brute force for each of them
* If the ans in num, then ci|num==num
*/
void solve(){
	ll n, m;
	cin>>n>>m;

	vll a(n, 0), b(m, 0);

	rep(i, n) cin>>a[i];
	rep(i, m) cin>>b[i];
		
	rep(num, 513){
		bool ok = 1;
		rep(i, n){
			bool okk = 0;
			rep(j, m){
				if(((a[i]&b[j])|num)==num){
					okk=1;
					break;
				}
			}
			if(!okk) ok=0;
		}
		if(ok){
			cout << num << '\n';
			return;
		}
	}

	return;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	solve();
 	return 0 ; 
}

