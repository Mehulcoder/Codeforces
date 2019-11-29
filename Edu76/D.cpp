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
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		vector<int> monster(n,0);
		for (int i = 0; i < n; ++i)
		{
			cin>>monster[i];
		}

		int m;
		cin>>m;

		vector<pii> hero(m, {0,0});
		//vector<pii> hero(m, 0);
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			cin>>a>>b;
			hero[i] = {a, b};
		}

		vector<int> a(n+1, 0);
		for (int i = 0; i < m; ++i)
		{
			a[hero[i].s] = max(a[hero[i].s], hero[i].f);
		}

		int updater = INT_MIN;
		for (int i = n; i >= 1; --i)
		{
			updater = max(updater, a[i]);
			if (a[i]<updater)
			{
				a[i] = updater;
			}
		}


		// for (int i = 0; i < n+1; ++i)
		// {
		// 	cout << i<<" "<<a[i] << '\n';
		// }

		int pos = 0;
		int res = 0;
		bool ok = 1;
		//debug(a[1])
		while(pos<n){
			res++;
			int npos = pos;
			int mx = 0;
			while(1){
				mx = max(mx, monster[npos]);
				if (mx>a[npos-pos+1])
				{
					// debug(mx);
					//debug(npos-pos+1)
					break;
				}
				npos++;
			}

			if(pos == npos){
				ok = false;
				break;
			}
			pos = npos;
		}

		if(!ok) res = -1;
		//printf("%d\n", res);
		cout << res << '\n';
	}
	



	return 0 ; 



}

