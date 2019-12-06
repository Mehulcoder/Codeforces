#include <bits/stdc++.h>
using namespace std;
 
const int borne = (int)(1e6) + 5;
const int WAIT=0, ENTERED=1, LEFT=2;
int state[borne];
 
bool solve()
{
    ios::sync_with_stdio(false);
    int nbEvents;
    cin >> nbEvents;
    vector<int> res, cur;
    int ofs = 0;
 
    for (int ind = 0; ind < nbEvents; ++ind) {
        int ev; cin >> ev;
        int guy = abs(ev);
        cur.push_back(guy);
        if (ev > 0) {
            if (state[guy] != WAIT) return false;
            state[guy] = ENTERED; ++ofs;
        } else {
            if (state[guy] != ENTERED) return false;
            state[guy] = LEFT; --ofs;
        }
        if (ofs == 0) {
            res.push_back(cur.size());
            for (int x : cur) state[x] = WAIT;
            cur.clear();
        }
    }
 
    if (! cur.empty()) return false;
 
    int nbDays = res.size();
    cout << nbDays << "\n";
    for (int i = 0; i < nbDays; ++i) {
        cout << res[i];
        if (i+1 < nbDays) cout << " ";
        else cout << "\n";
    }
    return true;
}
 
int main()
{
    if (!solve()) cout << "-1\n";
    return 0;
}