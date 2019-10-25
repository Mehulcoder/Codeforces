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
		int evecount = 0;
		int evenotpal = 0;
		int oddcount = 0;
		int ans = 0;

		for (int i = 0; i < n; ++i)
		{
			string s;
			cin>>s;
			if (s.size()%2==0)
			{
				int zero = 0;
				int one = 0;
				for (int j = 0; j < s.size(); ++j)
				{
					if (s[j]=='1')
					{
						one++;
					}else{
						zero++;
					}
				}

				if (one%2!=0)
				{
					evenotpal++;
				}else{
					evecount++;
				}

			}else{
				oddcount++;
				//ans++;
			}
		}

		if (oddcount>0)
		{
			cout<<n<<endl;;
		}else{
			cout << evecount+(evenotpal/2)*2 << '\n';
		}
	}



	return 0 ; 



}
