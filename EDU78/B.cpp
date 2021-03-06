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
		int a, b;
		cin>>a>>b;

		int operations = 0;
		int temp1 = min(a,b);
		int temp2 = max(a,b);

		a = temp1;
		b = temp2;
		// cout << b << '\n';


		a-=temp1;
		b-=temp1;
		// cout << a << '\n';

		long double k = 0;
		k = (-1.0+sqrt(1.0+8.0*b))/2.0;

		operations = floor(k);
		int next = operations+1;
		cout << next << '\n';
		a+=((operations)*(operations+1))/2;
		cout << a<<" "<<b << '\n';


		// cout << operations << '\n';
	}

	



	return 0 ; 



}

