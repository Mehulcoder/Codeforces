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
		int n, m;
		cin>>n>>m;

		vector<int> v1(n, 0);
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>v1[i];
			sum+=v1[i];
		}

		sort(all(v1));

		if (m<n || n<=2)
		{
			cout<<-1<<endl;
			continue;
		}

		cout << sum*2 << '\n';

		for (int i = 1; i <= n; ++i)
		{
			cout<<i<<" "<<(i%n+1)<<endl;
		}


	}
	



	return 0 ; 



}

