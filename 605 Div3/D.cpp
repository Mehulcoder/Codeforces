#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], l[maxn], r[maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], l[i] = 1, r[i] = 1;
    int ans = 1;
    for (int i = n-2; i >= 0; i--)
        if (a[i+1] > a[i]) l[i] = l[i+1] + 1, ans = max(ans, l[i]);
    for (int i = 1; i < n; i++)
        if (a[i] > a[i-1]) r[i] = r[i-1] + 1, ans = max(ans, r[i]);
    for (int i = 0; i < n - 2; i++)
        if (a[i + 2] > a[i]) ans = max(ans, r[i] + l[i+2]);
    cout << ans << endl;
}