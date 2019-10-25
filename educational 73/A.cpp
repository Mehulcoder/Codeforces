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
		vector<ll> input(n, 0); 
		for (int i = 0; i < n; ++i)
		{
			cin>>input[i];
		}
		unordered_map<ll, int> mymap;

		for (int i = 0; i < n; ++i)
		{
			if(input[i]<=2048){
				mymap[input[i]]++;
			}
		}

		while(1){
//			cout << q << '\n';

			if (mymap[2048]>0)
			{
				cout << "YES" << '\n';
				break;
				//return 0;
			}
			

			int flag = 0;
			auto it = mymap.begin();
			while(it!=mymap.end()){
				if (mymap[2048]>0)
				{
					cout << "YES" << '\n';
					//return 0;
					flag = 2;
					break;
					
				}
				if (it->s>=2)
				{
					//cout << "here" << '\n';
					//cout << it->f<<" "<<it->s << '\n';

					flag = 1;
					mymap[(it->f)*2]++;
					it->s = it->s-2;
				//	cout << mymap[512] << '\n';
				}

				if (mymap[2048]>0)
				{
					cout << "YES" << '\n';
					//return 0;
					flag = 2;
					break;
					
				}
				it++;
			}
			


			if (flag == 0)
			{
				cout << "NO" << '\n';
				break;
			}else if(flag == 2){
				break;
			}

		}

	}


	return 0 ; 



}
