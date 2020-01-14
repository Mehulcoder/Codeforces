    #include <iostream>
    #include <string>
    #include <vector>
    #include <fstream>
    #include <algorithm>
    #include <math.h>
    #include <map>
    using namespace std;
     
    map<string,int> m;
    string s[1505];
    int ans=0;
    int main(){
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
     cin>>s[i];
     m[s[i]]++;
    }
    for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++){
        string t="";
        for(int a=0;a<k;a++){
            if(s[i][a]==s[j][a])t+=s[i][a];
            else if(s[i][a]!='S'&&s[j][a]!='S')t+='S';
            else if(s[i][a]!='T'&&s[j][a]!='T')t+='T';
            else t+='E';
        }
        ans+=m.count(t);
    }
    cout<<ans/3;
    }