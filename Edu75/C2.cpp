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
	cin >> t;

	while(t--)
	{
		string s;
		cin >> s;

		int n = s.length();

		int *arr = new int[n];

		for(int i=0;i<n;i++)
			arr[i] = s[i] - '0';


		int *aux = new int[n];

		vector<int> even;
		vector<int> odd;

		for(int i=0;i<n;i++)
		{
			if(arr[i]%2 == 0)
				even.push_back(i);
			else
				odd.push_back(i);
		}

		int idx = 0;
		for(int i=0;i<even.size();i++)
			aux[idx++] = arr[even[i]];

		for(int i=0;i<odd.size();i++)
			aux[idx++] = arr[odd[i]];


		//cout << even.size() << " " << odd.size() << endl;

		int idx1 = 0; //for even
		int idx2 = even.size(); //for odd



		vector<int> final;

		for(;idx2<n;)
		{
			if(idx1 == even.size())
			{
				final.push_back(aux[idx2++]);
				continue;
			}

			int flag = 0;

			for(;idx1<even.size();idx1++)
			{
				if(aux[idx2] < aux[idx1])
				{
					flag = 1;
					break;
				}
				else
				{
					final.push_back(aux[idx1]);
				}
			}

			if(flag == 1)
			{
				final.push_back(aux[idx2]);
				idx2++;
			}
		}

		for(;idx1<even.size();idx1++)
			final.push_back(aux[idx1]);

		for(int i=0;i<final.size();i++)
			cout << final[i];
		cout << endl;

	}



	return 0 ; 



}
