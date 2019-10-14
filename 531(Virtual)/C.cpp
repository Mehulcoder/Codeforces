/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
You are policeman and you are playing a game with Slavik. The game is turn-based and each turn consists of two phases. During the first phase you make your move and during the second phase Slavik makes his move.

There are nn doors, the ii-th door initially has durability equal to aiai.

During your move you can try to break one of the doors. If you choose door ii and its current durability is bibi then you reduce its durability to max(0,bi−x)max(0,bi−x) (the value xx is given).

During Slavik's move he tries to repair one of the doors. If he chooses door ii and its current durability is bibi then he increases its durability to bi+ybi+y (the value yy is given). Slavik cannot repair doors with current durability equal to 00.

The game lasts 1010010100 turns. If some player cannot make his move then he has to skip it.

Your goal is to maximize the number of doors with durability equal to 00 at the end of the game. You can assume that Slavik wants to minimize the number of such doors. What is the number of such doors in the end if you both play optimally?

Input
The first line of the input contains three integers nn, xx and yy (1≤n≤1001≤n≤100, 1≤x,y≤1051≤x,y≤105) — the number of doors, value xx and value yy, respectively.

The second line of the input contains nn integers a1,a2,…,ana1,a2,…,an (1≤ai≤1051≤ai≤105), where aiai is the initial durability of the ii-th door.

Output
Print one integer — the number of doors with durability equal to 00 at the end of the game, if you and Slavik both play optimally.
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
	
	int n, x, y;
	cin>>n>>x>>y;
	if (x>y)
	{
		cout << n << '\n';
		return 0;
	}

	int*arr = new int[n]();
	int count = 0;

	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		if (arr[i]<=x)
		{
			count++;
		}
	}

	//ceil()
	cout << ceil((count*1.0)/2.0) << '\n';
	return 0 ; 



}
