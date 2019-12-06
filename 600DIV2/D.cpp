#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>g[200009];
ll n,m,x,y,ans,mx,vis[200009];
void dfs(ll v){
    mx=max(v,mx),vis[v]=1;
    for(int i=0;i<g[v].size();i++) if(!vis[g[v][i]]) dfs(g[v][i]);
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(mx>i)ans++;
            dfs(i);
        }
    }
    cout<<ans;
}