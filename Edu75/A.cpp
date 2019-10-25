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
	cin>>t;
	while(t--){
		set<char> undefected;
		set<char> maybedefected;

		
		string s;
		cin>>s;
		int n = s.size();
		int i = 0;
		while(i<n){
			if (s[i]!=s[i+1])
			{
				undefected.insert(s[i]);
				i++;
			}else{
				maybedefected.insert(s[i]);
				i = i+2;
			}
		}

		auto it1 = undefected.begin();
		auto it2 = maybedefected.begin();
		while(it1!=undefected.end()){
			cout << *it1 ;
			it1++;
		}

		// while(it2!=maybedefected.end()){
		// 	if (undefected.find((*it2)) == undefected.end())
		// 	{
		// 		cout<<*it2;
		// 	}
		// 	it2++;
		// }
		cout << '\n';
	}


	return 0 ; 



}
