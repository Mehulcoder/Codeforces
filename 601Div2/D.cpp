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
	ci>>t;

	while(t--){
		int r,c,k;
		cin>>r>>c>>k;
		char**ans = new char*[r];
		for (int i = 0; i < r; ++i)
		{
			ans[i] = new char[c];
			for (int j = 0; j < c; ++j)
			{
				ans[i][j] = ' ';
			}
		}

		vector<string> v1(r);
		int rice = 0;
		for (int i = 0; i < r; ++i)
		{
			cin>>v1[i];
			for (int j = 0; j < c; ++j)
			{
				if (v1[i][j] == 'R')
				{
					rice++;
				}
			}
		}		

		string text = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		int count = 0;
		//int rice = 0;
		int av = rice/k;
		int diff = rice-av*k;

		int hisrice = 0;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				int J = j;
				if (i%2!=0)
				{
					J=c-1-j;
				}
				ans[i][J] = text[count];
				if (v1[i][J]=='R')
				{
					hisrice++;
					if (hisrice==av+(diff>0))
					{
						count++;
						hisrice = 0;
						diff--;
					}

				}
			}
		}


		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cout<<ans[i][j];
			}
			cout << '\n';
		}
	}
	



	return 0 ; 



}

