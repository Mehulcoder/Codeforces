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


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,a,b,c;
		cin>>n>>a>>b>>c;
		string s;
		cin>>s;
		char *arr = new char[n];
		int i=0,cnt=0;
		while(s[i]!='\0')
		{
			arr[i]='$';
			if(s[i]=='R' && b!=0)
				{b--;cnt++;arr[i]='P';}
			if(s[i]=='P' && c!=0)
				{c--;cnt++;arr[i]='S';}
			if(s[i]=='S' && a!=0)
				{a--;cnt++;arr[i]='R';}
			i++;
		}
		if(cnt>=ceil((double)n/2))
		{
			cout<<"yes"<<endl;
			for(int i=0;i<n;i++)
			{
				if(arr[i]=='$')
				{
					if(a!=0)
						{cout<<"R";a--;}
					else if(b!=0)
						{cout<<"P";b--;}
					else if(c!=0)
						{cout<<"S";c--;}
				}
				else
					cout<<arr[i];
			}
			cout<<endl;
		}
		else
			cout<<"no"<<endl;
	}
	return 0;
}
