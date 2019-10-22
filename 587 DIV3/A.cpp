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
	
	int n;
	cin>>n;
	string s;
	cin>>s;
	
	int i = 1;
	int count = 0;
	int k = ((n/2)*2)-1;
	while(i<=k){
		if (s[i]==s[i-1])
		{
			count++;
			if (s[i]=='a')
			{
				s[i-1] = 'b';
			}else
			{
				s[i-1] = 'a';
			}
		}
		i=i+2;
	}

	cout << count << '\n';
	cout<<s<<endl;

	return 0 ; 



}
