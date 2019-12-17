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
	
	int n;
	cin>>n;
	vector<int> v1(n-1, 0);

	for (int i = 0; i < n-1; ++i)
	{
		cin>>v1[i];
	}

	int prev = 1;
	int minimum = 1;
	vector<int> ans(n, 0);
	ans[0] = 1;
	for (int i = 0; i < n-1; ++i)
	{
		prev += v1[i];
		ans[i+1] = prev;
		minimum = min(prev, minimum);
	}
	
	int a = INT_MIN;
	int b = INT_MAX;
	unordered_map<int, int> m1;
	for (int i = 0; i < n; ++i)
	{
		ans[i] += 1-minimum;
		m1[ans[i]]++;
	}

	int flag = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (m1[i]!=1)
		{
			flag = 0;
			break;
		}
	}
	if (flag==0)
	{
		cout << -1 ;
	}

	for (int i = 0; i < n && flag == 1; ++i)
	{
		cout << ans[i] << ' ';
	}
	cout << '\n';



	return 0 ; 



}

