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
	
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
	    long long int temp=0;
		for(long long int i=0;i<n;i++)
		{
			if(s[i]=='0' && k>0)
			{
				if(k>=(i-temp))
				{
				   swap(s[temp],s[i]);
				   k-=(i-temp);
			    }
				else
				{
				  swap(s[i],s[i-k]);k=0;
				}
				  
				temp=temp+1;
			}
		}
		cout<<s<<endl;
	}
	return 0;


}

