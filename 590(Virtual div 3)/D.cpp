/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
You are given a string ss consisting of lowercase Latin letters and qq queries for this string.

Recall that the substring s[l;r]s[l;r] of the string ss is the string slsl+1…srslsl+1…sr. For example, the substrings of "codeforces" are "code", "force", "f", "for", but not "coder" and "top".

There are two types of queries:

1 pos c1 pos c (1≤pos≤|s|1≤pos≤|s|, cc is lowercase Latin letter): replace sposspos with cc (set spos:=cspos:=c);
2 l r2 l r (1≤l≤r≤|s|1≤l≤r≤|s|): calculate the number of distinct characters in the substring s[l;r]s[l;r].
Input
The first line of the input contains one string ss consisting of no more than 105105 lowercase Latin letters.

The second line of the input contains one integer qq (1≤q≤1051≤q≤105) — the number of queries.

The next qq lines contain queries, one per line. Each query is given in the format described in the problem statement. It is guaranteed that there is at least one query of the second type.

Output
For each query of the second type print the answer for it — the number of distinct characters in the required substring in this query.


*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define pi pair<int,int>
#define ppi pair<int,pi >
#define ld long double
#define pb push_back
#define mod 1000000007
#define F first
#define S second
#define endl "\n"
 
void buildTree(int *a,int *tree,int start,int end,int node){
  if(start==end){
    tree[node]=a[start];
    return ;
  }
  int mid=(start+end)/2;
  buildTree(a,tree,start,mid,2*node);
  buildTree(a,tree,mid+1,end,2*node+1);
  tree[node]=(tree[2*node]+tree[2*node+1]);
}
 
void updateTree(int *a,int *tree,int start,int end,int treeNode,int index,int value){
  if(start==end){
    a[index]=value;
    tree[treeNode]=value;
    return ;
  }
  int mid=(start+end)/2;
  if(index>=start && index<=mid){
    updateTree(a,tree,start,mid,2*treeNode,index,value);
  }else{
    updateTree(a,tree,mid+1,end,2*treeNode+1,index,value);
  }
  tree[treeNode]=(tree[2*treeNode]+tree[2*treeNode+1]);
}
 
 
int query(int *a,int *tree,int start,int end,int treeNode,int left,int right){
  if(start>right || end<left){
    return 0;
  }
  if(start>=left && end<=right){
    return tree[treeNode];
  }
  int mid=(start+end)/2;
  return (query(a,tree,start,mid,2*treeNode,left,right)+query(a,tree,mid+1,end,2*treeNode+1,left,right));
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    string s;
    cin>>s;
    int n=s.length();
    int **arr=new int*[26];
    for(int i=0;i<26;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        int idx=(s[i]-97);
        arr[idx][i]=1;
    }
    int **tree=new int*[26];
    for(int i=0;i<26;i++){
        tree[i]=new int[4*n];
        buildTree(arr[i],tree[i],0,n-1,1);
    }
    int q;
    cin>>q;
    while(q--){
        int a;
        cin>>a;
        if(a==1){
            int b;
            cin>>b;
            char c;
            cin>>c;
            int idx=((int)(c)-97);
            int idx2;
            for(int i=0;i<26;i++){
                if(arr[i][b-1]==1){
                    idx2=i;
                    break;
                }
            }
            updateTree(arr[idx2],tree[idx2],0,n-1,1,b-1,0);
            updateTree(arr[idx],tree[idx],0,n-1,1,b-1,1);
        }else{
            int b,c;
            cin>>b>>c;
            int res=0;
            for(int i=0;i<26;i++){
                int ans=query(arr[i],tree[i],0,n-1,1,b-1,c-1);
                if(ans>0){
                    res++;
                }
            }
            cout<<res<<endl;
        }
    }
    return 0;
}