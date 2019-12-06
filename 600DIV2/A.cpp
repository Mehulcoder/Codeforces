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
		int n;
		cin>>n;

		vector<int> v1(n, 0);
		vector<int> v2(n, 0);

		for (int i = 0; i < n; ++i)
		{
			cin>>v1[i];
		}

		for (int i = 0; i < n; ++i)
		{
			cin>>v2[i];
		}

		int flag = 0;
		int start = 0;
		int count = 0;
		int i = 0;
		int diff = 0;
		while(i<n){
			if (start == 1)
			{
				break;
			}
			if (v1[i]>v2[i])
			{
				flag = 1;
				break;
			}
			if (v1[i] != v2[i])
			{
				diff = v2[i]-v1[i];
				count++;
				while(i<n && v1[i]!=v2[i]){	
					if (v2[i]-v1[i]!=diff)
					{
						start = 1;
						break;
					}
					i++;
				}
			}
			i++;
		}

	//	cout << count << '\n';
		if (count<=1 && flag == 0 && start == 0)
		{
			cout<<"YES"<<endl;
		}else{
			cout << "NO" << '\n';
		}

	}

	return 0 ; 



}

