class Solution {
public:
	set<string> m;
	string s1;
	vector<int> dp;
	bool get(int end) {
		if (m.find(s1.substr(0, end + 1)) != m.end()) {
			return 1;
		}

		int &anss = dp[end];
		if (anss != -1) return anss;
		for (int len = 1; len < end + 1; len++) {
			bool ans = 0;
			if (m.find(s1.substr(len, end - len + 1)) != m.end()) ans = 1;
			ans &= get(len - 1);
			if (ans) return anss = 1;
		}
		return anss = 0;
	}

	bool wordBreak(string s, vector<string>& wordDict) {
		m.clear();
		s1 = s;
		int n = s.size();
		dp.resize(n, -1);
		for (int i = 0; i < wordDict.size(); ++i) {
			m.insert(wordDict[i]);
		}

		return get(n - 1);
	}
};