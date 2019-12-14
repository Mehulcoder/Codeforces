#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int i,m,n,s,p[102];
int main(){
 
 
	for(scanf("%d",&n);i++<n;)scanf("%d",p+i);p[i]=1001;
	for(i=0;i++<n;)(p[i-1]+1==p[i] && p[i]+1==p[i+1])?s++:s=0,m>s?:m=s;
	printf("%d",m);
	
}
