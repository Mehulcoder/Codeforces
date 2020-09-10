class Solution {
public:
	using pii = pair<int, int>;
	int n;
	vector<vector<pair<int, int>>> edges;
	vector<int> dist;
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		const int inf = 1e9;
		n = N;
		dist.resize(N, inf);
		edges.resize(N);
		for (int i = 0; i < times.size(); ++i) {
			edges[times[i][0] - 1].push_back({times[i][1] - 1, times[i][2]});
		}

		dist[K] = 0;
		multiset<pii> pq;
		pq.insert({0, K});

		while (!pq.empty()) {
			auto p = *(pq.begin());
			pq.erase(pq.begin());
			int u = p.second;
			for (auto &to : edges[p.second]) {
				int v = to.first; int w = to.second;
				if (dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
					pq.insert({dist[v], v});
				}
			}
		}
		int ans;
		ans = *(max_element(dist.begin(), dist.end()));
		return (ans == inf) ? -1 : ans;
	}
};