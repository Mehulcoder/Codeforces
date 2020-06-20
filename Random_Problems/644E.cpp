#include <bits/stdc++.h>

using namespace std;

bool a[50][50];

int main() {
  int tests;
  cin >> tests;
  while (tests--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        char c;
        cin >> c;
        a[i][j] = c - '0';
      }
    }

    bool ans = true;
    for (int i = n - 2; i >= 0; --i) {
      for (int j = n - 2; j >= 0; --j) {
        if (a[i][j] && !a[i + 1][j] && !a[i][j + 1]) {
          ans = false;
        }
      }
    }

    cout << (ans ? "YES" : "NO") << endl;
  }
}