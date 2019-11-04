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
	while(q--){
		int n;
		cin>>n;

		vector<int> arr(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		
		vector<int> marked(n, 0);

		for (int i = 1; i <= n; ++i)
		{
			int flag = 0;
			for (int j = 0; j < n; ++j)
			{
				if (arr[j] == i)
				{
					while(j!=0 && marked[j-1]!=1 && arr[j-1]>arr[j]){
						if (j==i-1)
						{
							break;
						}
						swap(arr[j-1], arr[j]);
						marked[j-1] = 1;
						j--;
					}
					flag = 1;

				}
				if (flag == 1)
				{
					break;
				}
			}
		}

		for (int i = 0; i < n; ++i)
		{
			cout << arr[i] << ' ';
		}
		cout <<  '\n';
	}
	



	return 0 ; 



}

