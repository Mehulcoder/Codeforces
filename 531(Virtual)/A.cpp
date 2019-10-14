/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
You are given an integer sequence 1,2,…,n1,2,…,n. You have to divide it into two sets AA and BB in such a way that each element belongs to exactly one set and |sum(A)−sum(B)||sum(A)−sum(B)| is minimum possible.

The value |x||x| is the absolute value of xx and sum(S)sum(S) is the sum of elements of the set SS.

Input
The first line of the input contains one integer nn (1≤n≤2⋅1091≤n≤2⋅109).

Output
Print one integer — the minimum possible value of |sum(A)−sum(B)||sum(A)−sum(B)| if you divide the initial sequence 1,2,…,n1,2,…,n into two sets AA and BB.
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
	
	ll n;
	cin>>n;

	if ((n-1)%4==0 || (n-2)%4==0)
	{
		cout << 1 << '\n';
		return 0;
	}else{
		cout << 0 << '\n';
		return 0;
	}


	return 0 ; 



}
