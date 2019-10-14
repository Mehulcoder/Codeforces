/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
Let's call the following process a transformation of a sequence of length nn.

If the sequence is empty, the process ends. Otherwise, append the greatest common divisor (GCD) of all the elements of the sequence to the result and remove one arbitrary element from the sequence. Thus, when the process ends, we have a sequence of nn integers: the greatest common divisors of all the elements in the sequence before each deletion.

You are given an integer sequence 1,2,…,n1,2,…,n. Find the lexicographically maximum result of its transformation.

A sequence a1,a2,…,ana1,a2,…,an is lexicographically larger than a sequence b1,b2,…,bnb1,b2,…,bn, if there is an index ii such that aj=bjaj=bj for all j<ij<i, and ai>biai>bi.

Input
The first and only line of input contains one integer nn (1≤n≤1061≤n≤106).

Output
Output nn integers  — the lexicographically maximum result of the transformation.
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

	vector<int> ans;
	int factor = 1;
	
	while(n>0){
		
		int times = (n+1)/2;
		if (n==3)
		{
			while(times--){
				ans.push_back(factor);
			}
			int temp = n*factor;
			ans.push_back(temp);
			break;
		}

		while(times--){
			ans.push_back(factor);
		}

		n = (n-((n+1)/2));
		factor = 2*factor;
	}

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << ' ';
	}
	cout <<'\n';

	return 0 ; 



}
