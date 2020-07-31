#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    int n;
    long long int ans;
    scanf("%d", &n);
 
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
 
    if(n==1){
        cout << arr[0];
        return 0;
    }
    
    sort(arr, arr + n);
    
    ans = arr[n - 1] - arr[0];
    for (int i = 1; i < n - 1; i++){
        ans = ans + abs(arr[i]);
    }
 
    printf("%lld", ans);
    return 0;
}
