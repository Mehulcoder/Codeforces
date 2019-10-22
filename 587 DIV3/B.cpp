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

bool mysort(pii a, pii b){
	return (a.first>b.first);
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin>>n;
	vector<pii> arr(n);

	for (int i = 0; i < n; ++i)
	{
		int a;
		cin>>a;
		arr[i] = {a, i};
	}

	sort(arr.begin(), arr.end(), mysort);

	ll cost = 0;
	int cansshot = 0;
	for (int i = 0; i < n; ++i)
	{
		cost+=arr[i].first*cansshot+1;
		cansshot++;
	}

	cout << cost << '\n';
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i].second+1 << ' ';
	}


	cout << '\n';



	return 0 ; 



}
