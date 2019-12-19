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
	
	int t;
	cin>>t;
	while(t--){
		string s1, s2;
		cin>>s1>>s2;

		map<int, int> m1;
		for (int i = 0; i < s1.size(); ++i)
		{
			m1[s1[i]-'a']++;
		}

		int flag = 0;

		for (int start = 0; start < s2.size(); ++start)
		{
			for (int end = s2.size()-1; end >= start; --end)
			{
				// set<int> b;
				map<int, int> m2;
				for (int i = start; i <= end; ++i)
				{
					// b.insert(s2[i]-'a');
					m2[s2[i]-'a']++;
				}

				if (m1==m2)
				{
					cout << "YES" << '\n';
					flag = 1;
					break;
				}
			}

			if (flag==1)
			{
				break;
			}
		}

		if (flag==0)
		{
			cout << "NO" << '\n';
		}
		
	}
	



	return 0 ; 



}

