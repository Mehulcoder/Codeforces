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
	
	int a, b;
	cin>>a>>b;

	if (a==b)
	{
		cout << a*10<<" "<<a*10+1 << '\n';
		return 0;
	}

	if (a==9 && b==1)
	{
		cout << a<<" "<<a+1 << '\n';
		return 0;
	}

	if (a==b+1)
	{
		cout << -1 << '\n';
		return 0;
	}


	if (a+1==b)
	{
		cout << a<<" "<<b << '\n';
		return 0;
	}

	cout << -1 << '\n';

	return 0 ; 



}
