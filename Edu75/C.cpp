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

int arr[1000000];

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n = s.size();
		for (int i = 0; i < n; ++i)
		{
			arr[i] = s[i] - '0';
		}

		// for (int i = 0; i < n; ++i)
		// {
		// 	cout << arr[i] << '\n';
		// }
		
		int start = 0;
		while(start!=n-1){
			int next = arr[start+1];
			int now = arr[start];

			if (abs(next%2-now%2)==1 && next<now)
			{
				swap(arr[start+1], arr[start]);
				int leftmover = start;
				while(leftmover!=0)
				{
					int prev = arr[leftmover-1];
					int rn = arr[leftmover];

					if (abs(rn%2-prev%2) == 1 && prev>rn)
					{
						swap(arr[leftmover-1], arr[leftmover]);
					}
					leftmover--;
				}
			}

			start++;
		}

		for (int i = 0; i < n; ++i)
		{
			cout << arr[i];
		}
		cout << '\n';

	}


	return 0 ; 



}
