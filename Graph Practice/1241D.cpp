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
const int MAXN = 1000000+3;
 
int n, m;
string a[MAXN];
 
bool rec(int x, int y){
    if(x == n-1 && y == m-1) return 1;
    if(x >= n || y >= m || a[x][y] == '#') return 0;
    if(x != 0 || y != 0) a[x][y] = '#';
    return rec(x + 1, y) || rec(x, y + 1);
}
 
int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(!rec(0,0)) cout << 0;
    else if(rec(0,0)) cout << 2;
    else cout << 1;
	

   

	return 0 ; 




}

