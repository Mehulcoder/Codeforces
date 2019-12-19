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
		int n;
		cin>>n;


		int o2 = INT_MAX;
		int t2 = INT_MAX;

		int o1 = INT_MIN;
		int t1 = INT_MIN;

		string right, left;
		for (int i = 0; i < n; ++i)
		{
			char c1;
			cin>>c1;

			left+=c1;
		}

		for (int i = n; i < 2*n; ++i)
		{
			char c1;
			cin>>c1;

			right+=c1;
		}
		string s = "";
		s = left+'0'+right;
		int two = 0;
		int one = 0;

		for (int i = 0; i < 2*n; ++i)
		{
			if (s[i]=='1')
			{
				one++;
			}else{
				two++;
			}
		}

		for (int i = n; i < 2*n; ++i)
		{
			if (s[i]=='1')
			{
				o2 = i;
				break;
			}
		}

		for (int i = n; i < 2*n; ++i)
		{
			if (s[i]=='2')
			{
				t2 = i;
				break;
			}
		}

		for (int i = 0; i < n; ++i)
		{
			if (s[i]=='1')
			{
				o1 = i;
			}
		}

		for (int i = 0; i < n; ++i)
		{
			if (s[i]=='2')
			{
				t1 = i;
			}
		}

		int jars = 0;
		if (one==two)
		{
			cout << jars << '\n';
			break;
		}

		cout << s << '\n';
		int curr = n;
		// debug(o1)

		while(1){
			if (one==two)
			{
				break;
			}

			if (one>two)
			{
				
			}
		}

	}
	



	return 0 ; 



}

