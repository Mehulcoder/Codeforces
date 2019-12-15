#pragma GCC optimize("O3")
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pi pair<int,int>
#define pl pair<ll,ll>
#define ppi pair<int,pi >
#define ppl pair<ll,pl >
#define ld long double
#define pb push_back
#define mod 1000000007
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        int flag1=0,flag0=0,flag=0;
        vector<int> start0;
        vector<int> start1;
        int count0=0,count1=0;
        unordered_set<string> s;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            s.insert(arr[i]);
        }
        for(int i=0;i<n;i++)
        {
            int m=arr[i].size();
            if(arr[i][0]=='0' && arr[i][m-1]=='0')
                flag0=1;
            else if(arr[i][0]=='1' && arr[i][m-1]=='1')
                flag1=1;
            else
            {
                if(arr[i][0]=='0')
                {
                    count0++;
                    string lol=arr[i];
                    reverse(lol.begin(),lol.end());
                    if(s.find(lol)==s.end())
                        start0.pb(i);
                }
                else
                {
                    count1++;
                    string lol=arr[i];
                    reverse(lol.begin(),lol.end());
                    if(s.find(lol)==s.end())
                        start1.pb(i);
                }
                flag=1;
            }
        }
        if(flag==0 && flag1==1 && flag0==1)
        {
            cout<<-1<<endl;
            continue;
        }
 
        
        int diff=count0-count1;
        if(diff>=0)
        {
            if((diff/2)>start0.size())
            {
                cout<<-1<<endl;
                continue;
            }
        }
        else
        {
            int lmao=diff*(-1);
            if((lmao/2)>start1.size())
            {
                cout<<-1<<endl;
                continue;
            }
        }
        bool temp=0;
        int index=0;
        vector<int> ans;
        while(diff>=0)
        {
            temp=1;
            if(diff<=1)
                break;
            ans.pb(start0[index]);
            index++;
            diff-=2;
        }
        if(temp==0)
        {
            diff*=-1;
            while(diff>=0)
            {
                if(diff<=1)
                    break;
                ans.pb(start1[index]);
                index++;
                diff-=2;
            }
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]+1<<" ";
        cout<<endl;
        
        
 
        
    }
 
    return 0;
}