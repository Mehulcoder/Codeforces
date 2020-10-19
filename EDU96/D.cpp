/*
Author: Mehul Chaturvedi
Talent is overrated
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

int ceil(int p, int q) {
    return (p + q - 1) / q;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> next(n + 1);
        next[n] = next[n - 1] = n;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == s[i + 1])
                next[i] = i;
            else
                next[i] = next[i + 1];
        }

        vector<int> aux;
        for (int i = 0;  i < n; i++) {
            int x = 1;
            while (i + x < n && s[i] == s[i + x])
                x++;
            aux.push_back(x);
            i += (x - 1);
        }

        set<int> gg;
        for (int i = 0; i <= n; i++)
            gg.insert(i);

        int res = 0, req = 0;
        for (auto pos = aux.begin(); pos != aux.end(); pos++) {
            int x = *pos;
            req += (x == 1);
            if (x != 1) {
                int yo = max(min(0LL, req), min(req, x - 2));
                req -= yo;
                res += ++yo;
            }
        }

        int finalAns = res + ceil(req, 2);
        if (n == 1)
            finalAns = 1;
        cout << finalAns << '\n';
    }

    return 0;
}