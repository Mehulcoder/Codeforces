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

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
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
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		unordered_map<string, int> m1;

		for (int i = 0; i < n; ++i)
		{
			string s;
			cin>>s;

			if (s[0]=='1' && s[s.size()-1]=='1')
			{
				m1["11"]++;
			}
			if (s[0]=='1' && s[s.size()-1]=='0')
			{
				m1["10"]++;
			}
			if (s[0]=='0' && s[s.size()-1]=='1')
			{
				m1["01"]++;
			}
			if (s[0]=='0' && s[s.size()-1]=='0')
			{
				m1["00"]++;
			}

			// DEBUG(s)
			// DEBUG(m1["01"])
		}

		if (m1["01"]==0 && m1["10"]==0 && m1["00"]!=0 && m1["11"]!=0)
		{
			cout << -1 << '\n';
			continue;
		}

		int ans = 0;

//Used at start
		if (m1["10"]>=2 && m1["11"]!=0)
		{
			m1["10"]-=2;
		}else if (m1["11"]==0)
		{
			int temp = min(m1["10"], m1["01"]);
			m1["10"] -= temp;
			m1["01"] -= temp;
			ans = max(m1["01"], m1["10"])/2;
			cout<<ans<<endl;
			continue;
		}

		int temp = min(m1["10"], m1["01"]);
		m1["10"] -= temp;
		m1["01"] -= temp;
//Used in last
		if (m1["10"]==0)
		{			
			ans = m1["01"]/2;
			cout << ans << '\n';
			continue;
		}else{
			ans = (m1["10"])/2+1;

			cout << ans << '\n';
			continue;
		}

//oo consumed
		m1["00"] = 0;

// start consuming pairs of 01 and 10

		

		// for(auto it: m1){
		// 	cout << it.first << " : "<<it.second;
		// 	cout <<  '\n';
		// }


	}
	



	return 0 ; 



}

