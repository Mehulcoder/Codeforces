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
	
	int x[7];
	int y[7];

	cin>>x[1];
	cin>>y[1];

	cin>>x[2];
	cin>>y[2];

	cin>>x[3];
	cin>>y[3];

	cin>>x[4];
	cin>>y[4];

	cin>>x[5];
	cin>>y[5];

	cin>>x[6];
	cin>>y[6];

	if (y[4]>=y[2] && y[3]<=y[1] && x[3]<=x[1] && x[4]>=x[2])
	{	
		//cout << "here1" << '\n';
		cout << "NO" << '\n';
		return 0;
	}

	if (y[6]>=y[2] && y[5]<=y[1] && x[5]<=x[1] && x[6]>=x[2])
	{
		//cout << "here2" << '\n';

		cout << "NO" << '\n';
		return 0;
	}

	if (x[4]>=x[1] && x[3]<=x[1] && y[4]>=y[2] && y[3]<=y[1])
	{
		if (x[6]>=x[2] && y[6]>=y[2] && y[5]<=y[1] && x[5]<=x[4])
		{
			//cout << "here3" << '\n';
			cout << "NO" << '\n';
			return 0;
		}
	}

	if (x[3]<=x[2] && y[4]>=y[2] && y[3]<=y[1] && x[4]>=x[2])
	{
		if (x[6]>=x[3] && y[6]>=y[2] && y[5]<=y[1] && x[5]<=x[1])
		{
		//cout << "here4" << '\n';

			cout << "NO" << '\n';
			return 0;
		}
	}

	if (y[4]>=y[2] && x[4]>=x[2] && x[3]<=x[1] && y[3]<=y[2])
	{
		if (x[6]>=x[2] && x[5]<=x[1] && y[5]<=y[1] && y[6]>=y[3])
		{
		//cout << "here5" << '\n';

			cout << "NO" << '\n';
			return 0;
		}
	}

	if (y[3]<=y[1] && x[6]>=x[2] && x[5]<=x[1] && y[4]>=y[1])
	{
		if (x[4]>=x[2] && x[3]<=x[1] && y[5]<=y[4] && y[6]>=y[2])
		{
			//cout << "here6" << '\n';

			cout << "NO" << '\n';
			return 0;
		}
	}

	cout << "YES" << '\n';



	return 0 ; 



}
