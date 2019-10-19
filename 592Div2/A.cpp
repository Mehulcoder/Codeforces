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
		int a, b, c, d, k;
		cin>>a>>b>>c>>d>>k;

		int pens = a/c;
		int pencils = b/d;
		if (pens*c<a)
		{
			pens = pens+1;
		}

		if (pencils*d<b)
		{
			pencils = pencils+1;
		}

		if (pens+pencils<=k)
		{
			cout << pens<<" "<<pencils << '\n';
		}else{
			cout << -1 << '\n';
		}



	}



	return 0 ; 



}
