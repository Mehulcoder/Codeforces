
/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;

using ll  = long long;

void dfs(int start, vector<vector<int>> &edges, vector<bool> &vis) {
	vis[start] = 1;
	for (auto &child : edges[start]) {
		if (!vis[child]) {
			dfs(child, edges, vis);
		}
	}

	return;
}

int countGroups(vector<string> related) {
	ll n = related.size();
	vector<vector<int>> edges(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (related[i][j] == '1' && i != j) {
				edges[i].push_back(j);
				edges[j].push_back(i);
			}
		}
	}

	int ans = 0;
	vector<bool> vis(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			ans++;
			dfs(i, edges, vis);
		}
	}

	return ans;
}

int main(int argc , char ** argv) {
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;


	return 0 ;
}