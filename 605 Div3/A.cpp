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
	
	int q;
	cin>>q;

	while(q--){
		vector<int> v1(3, 0);
		
		for (int i = 0; i < 3; ++i)
		{
			cin>>v1[i];
		}

		sort(all(v1));

		int ans = 0;

		int a = v1[0];
		int b = v1[1];
		int c = v1[2];

		if (a==b && b==c)
		{
			ans = 0;
		}else if (a==b && b!=c)
		{
			if (c-a==1 || c-a == 2)
			{
				ans = 0;
			}else{
				ans = 2*(c-a-2);
			}
		}else if (a!=b && b==c)
		{
			if (c-a==1 || c-a == 2)
			{
				ans = 0;
			}else{
				ans = 2*(c-a-2);
			}
		}else if (a!=b && b!=c)
		{
			ans = (b-a)+(c-a)+(c-b)-4;
		}

		cout << ans << '\n';
	}
	



	return 0 ; 



}

