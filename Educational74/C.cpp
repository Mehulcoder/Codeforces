/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
You are playing a game where your character should overcome different obstacles. The current problem is to come down from a cliff. The cliff has height hh, and there is a moving platform on each height xx from 11 to hh.

Each platform is either hidden inside the cliff or moved out. At first, there are nn moved out platforms on heights p1,p2,…,pnp1,p2,…,pn. The platform on height hh is moved out (and the character is initially standing there).

If you character is standing on some moved out platform on height xx, then he can pull a special lever, which switches the state of two platforms: on height xx and x−1x−1. In other words, the platform you are currently standing on will hide in the cliff and the platform one unit below will change it state: it will hide if it was moved out or move out if it was hidden. In the second case, you will safely land on it. Note that this is the only way to move from one platform to another.

Your character is quite fragile, so it can safely fall from the height no more than 22. In other words falling from the platform xx to platform x−2x−2 is okay, but falling from xx to x−3x−3 (or lower) is certain death.

Sometimes it's not possible to come down from the cliff, but you can always buy (for donate currency) several magic crystals. Each magic crystal can be used to change the state of any single platform (except platform on height hh, which is unaffected by the crystals). After being used, the crystal disappears.

What is the minimum number of magic crystal you need to buy to safely land on the 00 ground level?

Input
The first line contains one integer qq (1≤q≤1001≤q≤100) — the number of queries. Each query contains two lines and is independent of all other queries.

The first line of each query contains two integers hh and nn (1≤h≤1091≤h≤109, 1≤n≤min(h,2⋅105)1≤n≤min(h,2⋅105)) — the height of the cliff and the number of moved out platforms.

The second line contains nn integers p1,p2,…,pnp1,p2,…,pn (h=p1>p2>⋯>pn≥1h=p1>p2>⋯>pn≥1) — the corresponding moved out platforms in the descending order of their heights.

The sum of nn over all queries does not exceed 2⋅1052⋅105.

Output
For each query print one integer — the minimum number of magic crystals you have to spend to safely come down on the ground level (with height 00).
*/

#include <bits/stdc++.h>
 
using namespace std;
 
void solve()
{
	int h, n;
	cin >> h >> n;
	
	vector <int> v(n + 2);
	
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	
	int res = 0;
	
	for(int i = 1; i < n; i++)
	{
		if(v[i + 1] - v[i + 2] == 1)
			i++;
		else
		{
			res++;
			v[i + 1]--;
		}
	}
	
	cout << res << '\n';
}
 
main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	for(; t--;)
		solve();
}
