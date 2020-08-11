#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<long long>
#define repr(i, n) for (int i = n; i >= 0; i--)
#define vvll vector<vector<ll>>
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define INF 4557430888798830399ll
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)

void solve(){
	string s, t;
	cin>>s>>t;
	ll n = s.size(), m = t.size();
	vll mp(26, -1);

	vvll occurances(26, vll(n, INF));
	rep(i, n) occurances[s[i]-'a'][i] = (ll)i;
	rep(i, n) if(mp[s[i]-'a']==-1) mp[s[i]-'a']=i;

	rep(i, 26){
		ll mini = INF;
		repr(j, n-1){
			mini = min(mini, occurances[i][j]);
			occurances[i][j] = mini;
		}
	}

	ll ans = 1, lastIndex = -1;
	rep(i, m){
		ll curr = t[i]-'a';
		if(lastIndex!=n-1){
			lastIndex = occurances[curr][lastIndex+1];
			if(lastIndex == INF){
				ans++;
				if(mp[curr]==-1){ans=-1; break;}
				else lastIndex=mp[curr];
			}
		}else{
			ans++;
			if(mp[curr]==-1){ans=-1; break;}
			else lastIndex=mp[curr];
		}
	}

	cout << ans << '\n';
	return;

}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	ll t = 1;
	cin>>t;
	while(t--){
		solve();
	}
 	return 0 ; 
}

