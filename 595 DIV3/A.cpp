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
	
	int q;
	cin>>q;

	for (int i = 0; i < q; ++i)
	{
		int n;
		cin>>n;

		vector<int> arr(n, 0);
		for (int j = 0; j < n; ++j)
		{
			cin>>arr[j];
		}

		sort(arr.begin(), arr.end());
		int flag = 0;

		for (int j = 0; j < n-1; ++j)
		{
			if (arr[j+1]-arr[j] == 1)
			{
				flag = 1;
			}
		}

		if (flag == 1)
		{
			cout<<2<<endl;
		}else{
			cout << 1 << '\n';
		}
	}


	return 0 ; 



}
