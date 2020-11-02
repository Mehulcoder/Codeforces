
#include <bits/stdc++.h>
using namespace std;

const int N = 505;
vector<int> edges[N];
int n;
int vis[N];

int dfs(int root) {
	vis[root] = 1;
	set<int> s;
	for (auto &child : edges[root]) {
		s.insert(child);
	}

	/*
		Here we just check that if the child of child
		is from the set of childs of root, of so that means
		This is a cycle. You can simply get the the score of this trio
		By by removing 2*3 edges(due to trio members)
	*/
	int ans = INT_MAX;
	for (auto &child : edges[root]) {
		for (auto &cchild : edges[child]) {
			if (s.find(cchild) != s.end()) {
				int cnt = edges[root].size() + edges[child].size() + edges[cchild].size() - 6;
				ans = min(ans, cnt);
			}
		}
	}

	return ans;
}

int bestTrio(int friends_node, vector<int> friends_from, vector<int> friends_to) {
	n  = friends_node;
	for (int i = 0; i < N; ++i) {
		edges[i].clear();
	}
	memset(vis, -1, sizeof(vis));
	for (int i = 0; i < friends_from.size(); ++i) {
		edges[friends_from[i]].push_back(friends_to[i]);
		edges[friends_to[i]].push_back(friends_from[i]);
	}

	int ans = INT_MAX;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			ans = min(ans, dfs(i));
		}
	}


	return ans;
}