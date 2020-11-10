/*
Author: Mehul Chaturvedi
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;


void solve() {
	string s;
	cin >> s;
	ll n = s.size();
	deque<char> q;
	for (int i = 0; i < n; ++i) {
		q.push_back(s[i]);
	}

	set<deque<char>> st;
	for (int i = 0; i < n; ++i) {
		st.insert(q);
		q.push_front(q.back());
		q.pop_back();
	}

	cout << st.size() << '\n';
	return;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;

	ll t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0 ;
}