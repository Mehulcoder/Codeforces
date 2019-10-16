/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
You are given a system of pipes. It consists of two rows, each row consists of nn pipes. The top left pipe has the coordinates (1,1)(1,1) and the bottom right — (2,n)(2,n).

There are six types of pipes: two types of straight pipes and four types of curved pipes. Here are the examples of all six types:

Types of pipes
You can turn each of the given pipes 9090 degrees clockwise or counterclockwise arbitrary (possibly, zero) number of times (so the types 11 and 22 can become each other and types 3,4,5,63,4,5,6 can become each other).

You want to turn some pipes in a way that the water flow can start at (1,0)(1,0) (to the left of the top left pipe), move to the pipe at (1,1)(1,1), flow somehow by connected pipes to the pipe at (2,n)(2,n) and flow right to (2,n+1)(2,n+1).

Pipes are connected if they are adjacent in the system and their ends are connected. Here are examples of connected pipes:

Examples of connected pipes
Let's describe the problem using some example:

The first example input
And its solution is below:

The first example answer
As you can see, the water flow is the poorly drawn blue line. To obtain the answer, we need to turn the pipe at (1,2)(1,2) 9090 degrees clockwise, the pipe at (2,3)(2,3) 9090 degrees, the pipe at (1,6)(1,6) 9090 degrees, the pipe at (1,7)(1,7) 180180 degrees and the pipe at (2,7)(2,7) 180180 degrees. Then the flow of water can reach (2,n+1)(2,n+1) from (1,0)(1,0).

You have to answer qq independent queries.

Input
The first line of the input contains one integer qq (1≤q≤1041≤q≤104) — the number of queries. Then qq queries follow.

Each query consists of exactly three lines. The first line of the query contains one integer nn (1≤n≤2⋅1051≤n≤2⋅105) — the number of pipes in each row. The next two lines contain a description of the first and the second rows correspondingly. Each row description consists of nn digits from 11 to 66 without any whitespaces between them, each digit corresponds to the type of pipe in the corresponding cell. See the problem statement to understand which digits correspond to which types of pipes.

It is guaranteed that the sum of nn over all queries does not exceed 2⋅1052⋅105.

Output
For the ii-th query print the answer for it — "YES" (without quotes) if it is possible to turn some pipes in a way that the water flow can reach (2,n+1)(2,n+1) from (1,0)(1,0), and "NO" otherwise.
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
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n;
		string s[2];
		cin >> n >> s[0] >> s[1];
		int row = 0;
		int pos = 0;
		for (pos = 0; pos < n; ++pos) {
			if (s[row][pos] >= '3') {
				if (s[row ^ 1][pos] < '3') {
					break;
				} else {
					row ^= 1;
				}
			}
		}
		if (pos == n && row == 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	
	return 0;



}
