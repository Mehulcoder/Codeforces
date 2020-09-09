/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	using ll = long long int;
	ll ans = 0, sum = 0;
	long double minDiff = 1e15 * 1.0;
	ll get(TreeNode* root) {
		if (root == NULL) return 0;
		ll a = get(root->left);
		ll b = get(root->right);
		ll final = root->val + a + b;

		long double diff = abs(sum / 2.0 - final);
		if (minDiff > diff) {
			minDiff = diff;
			ans = max(ans, (sum - final) * (final));
		}

		return final;
	}

	ll getSum(TreeNode* root) {
		if (root == NULL) return 0;
		return root->val + getSum(root->left) + getSum(root->right);
	}

	int maxProduct(TreeNode* root) {
		sum  = getSum(root);
		get(root);
		return (int)(ans % (ll)(1e9 + 7));
	}
};
