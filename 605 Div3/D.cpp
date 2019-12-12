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

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
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

	vector<int> v1(n,0);
	for (int i = 0; i < n; ++i)
	{
		cin>>v1[i]
	}

	int* breakpoint = new int[n];
	int* iskaa = new int[n];
	for (int i = 0; i < n; ++i)
	{
		breakpoint[i] = 0;
		iskaa[i] = 0;
	}


	queue<int> q1;
	for (int i = 0; i < n-1; ++i)
	{
		if (v1[i]<=v1[i+1])
		{
			breakpoint[i+1]++;
			q1.push(i+1);
		}
	}

	int start = 0;
	int left = 0;
	while(q.size()!=0){
		int t = q.top();
		q.pop();
		while(start<t){
			iskaa[start] = (t-left);
			start++;
		}
		left = t;
	}

	int count = 1;
	for (int i = 0; i < n-1; ++i)
	{
		if (v1[i+1]>v1[i])
		{
			count++;
			iskaa[i] = count;
			count++;
		}else{
			count = 1;
			iskaa[i] = count;
		}
	}
	



	return 0 ; 



}

