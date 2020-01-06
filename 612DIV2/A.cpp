    #include<bits/stdc++.h>
    using namespace std;
     
    string str;
     
    int main()
    {
        int t,n;
        cin>>t;
    	while(t--)
    	{
    		
    		cin>>n>>str;
    		int pos=-1,ans=0;
    		
    		for(int i=0;i<str.length();i++)
    		{
    		    if(str[i]=='A') pos=i;
    			else if(pos!=-1)ans=max(ans,i-pos);	
    		}
    		cout<<ans<<endl;
    		}	
    }