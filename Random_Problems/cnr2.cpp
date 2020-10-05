#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    long int a, b, c, d, e, f, g, h, i, j, ans = 0;
    cin >> a;
    while (a--) {
        vector< pair <long int, long int> > vect;
        cin >> b >> c;
        for (d = 0; d < b; d++) {
            cin >> e >> f;
            vect.push_back(make_pair(e, f));
        }
        sort(vect.begin(), vect.end());
        ans = 0;
        for (d = 0; d < b; d++) {
            for (g = d + 1; g < b; g++) {
                if (abs(vect[d].first - vect[g].first) <= c) {
                    h = abs(vect[d].first - vect[g].first) + vect[d].second + vect[g].second;
                    ans = max(ans, h);
                } else {
                    break;
                }
            }
        }
        cout << ans << endl;
        vect.clear();
    }
    return 0;
}