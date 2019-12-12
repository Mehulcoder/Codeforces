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

int n;
int a[200005];
int l[200005];
int r[200005];
int ans;

int main()
{
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++)
	{
		if (a[i]>a[i-1]) l[i]=l[i-1]+1;
		else l[i]=1;
	}
	for (int i=n; i>=1; i--)
	{
		if (a[i]<a[i+1]) r[i]=r[i+1]+1;
		else r[i]=1;
	}
	ans=*max_element(l+1,l+n+1);
	for (int i=1; i<=n; i++) ans=max(ans,a[i-1]<a[i+1]?l[i-1]+r[i+1]:0);
	cout << ans << endl;
	return 0;
}

