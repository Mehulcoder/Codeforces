#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define ull unsigned long long
#define lli long long
#define pq priority_queue<int>
#define pql priority_queue<ll>
#define pqn priority_queue<node>
#define v vector<int>
#define vl vector<ll>
#define read(x) scanf("%d",&x)
#define lread(x) scanf("%lld",&x);
#define pt(x) printf("%d\n",(x))
#define YES printf("YES\n");
#define NO printf("NO\n");
#define gcd __gcd
#define out(x) cout<<x<<endl;
#define over cout<<endl;
#define rep(j,k) for (int i = (int)(j); i <= (int)(k); i++)
#define input(k) for (int i = 1; i <= (int)(k); i++)  {scanf("%d",&a[i]) ; }
#define mem(s,t) memset(s,t,sizeof(s))
#define ok return 0;
#define TLE std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod(x) ((x)%9973)
#define test cout<<"     ++++++      "<<endl;
//二叉树
#define lson rt<<1, l, m
#define rson rt<<1|1, m+1, r
//线段树
#define ls now<<1
#define rs now<<1|1
//int dir[6][3] = {0,0,1,0,0,-1,1,0,0,-1,0,0,0,1,0,0,-1,0};
//int dir[4][2] = {1,0,-1,0,0,1,0,-1}; //单位移动
//int dir[8][2] = {2,1,2,-1,-2,1,-2,-1,1,2,1,-2,-1,2,-1,-2};
int t,n,m,k,x,y,col,ex,ey,ans,cnt,ly;
string str;
int a[5];;
int main()
{
    while(cin>>n>>k)
    {
        cin>>str;
        if(!k)
            cout<<str<<endl;
        else if(n==1)
            cout<<0<<endl;
        else
        {
            if(str[0]!='1')
                {str[0] = '1';k--;}
            
            for(int i=1; i<str.size() && k; i++)
            {
                if(str[i]!='0')
                {str[i]='0';k--;}
 
            }
            cout<<str<<endl;
        }
    }
 
}