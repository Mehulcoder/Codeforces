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
	
	int q;
	cin>>q;

	while(q--){
		string s;
		cin>>s;

		int n = s.size();
		int l = 0;
		int r = 0;
		int u = 0;
		int d = 0;

		for (int i = 0; i < n; ++i)
		{
			if (s[i]=='L')
			{
				l++;
			}

			if (s[i]=='R')
			{
				r++;
			}

			if (s[i]=='U')
			{
				u++;
			}

			if (s[i]=='D')
			{
				d++;
			}
		}

		l = min(l, r);
		u = min(u, d);

		r = l;
		d = u;

		if (l==0)
		{
			if (u==0)
			{
				cout<<0<<endl;
			}else{
				cout<<2<<endl;
				cout << "UD" << '\n';
			}

			continue;
		}

		if (u==0)
		{
			if (l==0)
			{
				cout<<0<<endl;
			}else{
				cout<<2<<endl;
				cout << "LR" << '\n';
			}

			continue;
		}

		cout << (u+r)*2 << '\n';
		while(u--){
			cout <<'U';
		}
		while(r--){
			cout <<'R';
		}
		while(d--){
			cout <<'D';
		}
		while(l--){
			cout <<'L';
		}

		cout << '\n';
	}

	



	return 0 ; 



}

