#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;

int n;
string s, t;
int a[N];

int get(int x)
{
	int cur = 0, mx = 0;
	for(int i = 1; i <= n; i++)
	{
		cur += x * a[i];
		mx = max(mx, cur);
		if(cur < 0)
			cur = 0;
	}
	return mx;
}

int32_t main()
{
	IOS;
	cin >> n >> s >> t;
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		if(s[i - 1] != t[i - 1])
		{
			if(s[i - 1] == '1')
				a[i] = -1;
			else
				a[i] = 1;
		}
		sum += a[i];
	}
	if(sum != 0)
	{
		cout << -1;
		return 0;
	}
	int ans = max(get(1), get(-1));
	cout << ans;
	return 0;
}