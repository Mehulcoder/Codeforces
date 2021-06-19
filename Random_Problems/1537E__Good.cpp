#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k;
string s;
int main() {
    cin >> n >> k >> s;
    int len = 1;
    for (int i = 0; i < n && len < n; i++)
        if (s[i] > s[i % len]) break;
        else if (s[i] < s[i % len]) len = i + 1;
    for (int i = 0; i < k; i++) cout << s[i % len];
}