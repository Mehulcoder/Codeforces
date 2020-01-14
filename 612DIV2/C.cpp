#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int dp[MAXN][MAXN][2];
int A[MAXN];
 
int main(){
    int n; cin>>n;
    memset(dp, 0x3f, sizeof dp);
    for(int i = 1; i <= n; ++i){
        cin>>A[i];
        if(A[i]) A[i] = A[i]&1;
        else A[i] = -1;
    }
 
    dp[0][0][0] = dp[0][0][1] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            if(A[i]==-1){
                dp[i][j][0] = min(dp[i-1][j-1][0], dp[i-1][j-1][1]+1);
                dp[i][j][1] = min(dp[i-1][j][0]+1, dp[i-1][j][1]);
            }else{
                if(A[i]) dp[i][j][1] = min(dp[i-1][j][1], dp[i-1][j][0]+1);
                else dp[i][j][0] = min(dp[i-1][j-1][0], dp[i-1][j-1][1]+1);
            }
        }
    }
 
    cout<<min(dp[n][n/2][0], dp[n][n/2][1])<<endl;
    return 0;
}