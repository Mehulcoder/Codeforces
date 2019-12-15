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

#define MOD 1000000007


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin>>n;
	string s;
	cin>>s;

	string s2 = s;


	vector<int> white;
	vector<int> black;

	//Make white
	for (int i = 0; i < n-1; ++i)
	{
		if (s[i] == 'B')
		{
			white.push_back(i+1);
			s[i] = 'W';
			if (s[i+1]=='W')
			{
				s[i+1] = 'B';
			}else{
				s[i+1] = 'W';
			}
		}		
	}

	if (s[n-1]=='W')
	{
		cout << white.size() << '\n';
		for (int i = 0; i < white.size(); ++i)
		{
			cout << white[i] << ' ';
		}
		cout << '\n';


		return 0;
	}





	for (int i = 0; i < n-1; ++i)
	{
		if (s2[i] == 'W')
		{
			black.push_back(i+1);
			s2[i] = 'B';
			if (s2[i+1]=='W')
			{
				s2[i+1] = 'B';
			}else{
				s2[i+1] = 'W';
			}
		}		
	}


	if (s2[n-1]=='B')
	{
		cout << black.size() << '\n';
		for (int i = 0; i < black.size(); ++i)
		{
			cout << black[i] << ' ';
		}
		cout << '\n';

		return 0;
	}

	cout << -1 <<endl;

	return 0 ; 



}

