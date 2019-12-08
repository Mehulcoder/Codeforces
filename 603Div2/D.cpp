#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 100;

vector<int> g[N];
char used[N];

void addEdge(int v, int u) {
	g[v].push_back(u);
	g[u].push_back(v);
}

void dfs(int v) {
	used[v] = 1;

	for (int to : g[v]) {
		if (!used[to]) {
			dfs(to);
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (char c : s) {
			addEdge(i, n + c - 'a');
		}
	}

	int res = 0;

	for (int i = n; i < n + 26; i++) {
		if (!g[i].empty() && !used[i]) {
			dfs(i);
			res++;
		}
	}

	cout << res;

	return 0;
}