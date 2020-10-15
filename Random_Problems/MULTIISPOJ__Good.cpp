#include<bits/stdc++.h>
using namespace std;
#define mx 10004
vector<int>valid;
int vis[mx];
struct Node {
    string num;
    int mod;
    Node(string st, int md) {
        num = st;
        mod = md;
    }
};
string bfs(int n) {
    deque<Node> dq;
    for (int i = 0; i < valid.size(); i++) {
        if (valid[i] == 0) continue;
        string st = "";
        char ch = '0' + valid[i];
        st += ch;
        int md = valid[i] % n;
        if (md == 0) return st;
        dq.push_back(Node(st, md));
        vis[md]++;
    }
    while (!dq.empty()) {
        string num = dq.front().num;
        int mod = dq.front().mod;
        dq.pop_front();
        for (int i = 0; i < valid.size(); i++) {
            char ch = '0' + valid[i];
            int nmod = (mod * 10 + valid[i]) % n;
            if (vis[nmod] > 1) continue;
            if (nmod == 0) return (num + ch);
            dq.push_back(Node(num + ch, nmod));
            vis[nmod]++;
        }
    }
    return "-1";
}
int main() {
    ios_base::sync_with_stdio(0);
    int n, m, a, cs = 1;
    while (cin >> n >> m) {
        valid.clear();
        memset(vis, 0, sizeof vis);
        int v[12] = {0};
        for (int i = 1; i <= m; i++) {
            cin >> a;
            v[a] = 1;
        }
        for (int i = 0; i < 10; i++) {
            if (v[i] == 0) valid.push_back(i);
        }
        cout << "Case " << cs++ << ": " << bfs(n) << endl;;
    }
    return 0;
}
/**
2345 3
7 8 9
100 1
0
*/