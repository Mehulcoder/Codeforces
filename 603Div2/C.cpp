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
	
	int tt;
 	cin >> tt;
  	while (tt--) {
	    int n;
	    cin >> n;
	    vector<int> ans;
	    for (int i = 1; ;) {
	      //~ error(i, n/i);
	      ans.push_back(n/i);
	      if (n / i == 0) break;
	      i = n / (n / i) + 1;
    }
    sort(all(ans));
    cout << (ans.size()) << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
  }
  
  return 0;

	



	return 0 ; 



}

