class Solution {
public:
	using ll = long long int;
	vector<ll> v1, v2;
	bool get() {
		int n = min(v1.size(), v2.size());
		for (int i = 0; i < n; ++i) {
			if (v1[i] > v2[i]) return 1;
			else if (v1[i] < v2[i]) return 0;
		}

		return (v1.size() > v2.size());
	}

	int compareVersion(string version1, string version2) {
		string curr = "";
		for (int i = 0; i < version1.size(); ++i) {
			if (version1[i] == '.') {
				v1.push_back(stoll(curr));
				curr = "";
			} else {
				curr += version1[i];
			}
		}

		v1.push_back(stoll(curr));
		while (!v1.empty() && v1.back() == 0) {
			v1.pop_back();
		}
		curr = "";
		for (int i = 0; i < version2.size(); ++i) {
			if (version2[i] == '.') {
				v2.push_back(stoll(curr));
				curr = "";
			} else {
				curr += version2[i];
			}
		}
		v2.push_back(stoll(curr));

		while (!v2.empty() && v2.back() == 0) {
			v2.pop_back();
		}

		if (v1 == v2) {
			return 0;
		} else if (get()) {
			return 1;
		} else {
			return -1;
		}

	}

};