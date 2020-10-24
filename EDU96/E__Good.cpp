// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
// #define int long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> myset;

using LL = long long;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        string t = s;
        vector<int> g[26];
        for (int i = n - 1; i >= 0; i--)
            g[t[i] - 'a'].push_back(i);

        myset os;
        LL res = 0;
        for (int i = n - 1; i >= 0; i--) {
            LL x = g[t[i] - 'a'].back();
            LL k = os.size() - os.order_of_key(x);
            res += (x + k - (n - 1 - i));

            g[t[i] - 'a'].pop_back();
            os.insert(x);
        }

        cout << res << '\n';

    }

    return 0;
}

