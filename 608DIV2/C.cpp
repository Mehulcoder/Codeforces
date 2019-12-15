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
	
	int n, sx, sy;
	cin>>n>>sx>>sy;

	vector<int>x(n, 0);
	vector<int>y(n, 0);

	for (int i = 0; i < n; ++i)
	{
		cin>>x[i];
		x[i]-=sx;
		cin>>y[i];
		y[i]-=sy;
	}

	int a, b, c, d;
	int left, right, top, bottom;
	left=top=right=bottom=0;
	a=b=c=d=0;

	for (int i = 0; i < n; ++i)
	{
		if (x[i]>0 && y[i]>0)
		{
			right++;
			top++;

			a++;
		}
		if (x[i]>0 && y[i]<0)
		{
			bottom++;
			right++;
			b++;
		}
		if (x[i]<0 && y[i]<0)
		{
			left++;
			bottom++;

			c++;
		}
		if (x[i]<0 && y[i]>0)
		{
			top++;
			left++;
			d++;
		}

		if (y[i]==0 && x[i]>0)
		{
			right++;
		}

		if (y[i]==0 && x[i]<0)
		{
			left++;
		}

		if (x[i]==0 && y[i]>0)
		{
			top++;
		}

		if (x[i]==0 && y[i]<0)
		{
			bottom++;
		}

	}

	// debug(bottom);
	// debug(right)
	int temp = max(left, max(right, max(top, bottom)));

	if (temp == right)
	{
		cout<<temp<<endl;

		cout<<sx+1<<" "<<sy<<endl;
		return 0;
	}

	if (temp == left)
	{
		cout<<temp<<endl;

		cout<<sx-1<<" "<<sy<<endl;

		return 0;

	}

	if (temp == top)
	{
		cout<<temp<<endl;

		cout<<sx<<" "<<sy+1<<endl;

		return 0;

	}

	if (temp == bottom)
	{
		cout<<temp<<endl;

		cout<<sx<<" "<<sy-1<<endl;

		return 0;

	}

	// cout << top << '\n';





	return 0 ; 



}

