#include <bits/stdc++.h>
 
using namespace std;
 
char s1[20040];
char s2[20040];
 
int main() {
int t;
cin>>t;
while (t--)
{
   int n;
   scanf("%d",&n);
   scanf("%s",s1);
   scanf("%s",s2);
   int p1;
   int p2;
   int cnt=0;
   int flag=0;
   for (int a=0;a<n;a++)
   {
      if (s1[a]!=s2[a])
      {
         if (cnt==2)
         {
            flag=1;
            break;
			}
			if (cnt==1)
			{
			   p2=a;
			   cnt++;
			}
			if (cnt==0)
			{
			   p1=a;
			   cnt++;
			}
		}
	}
	if (cnt==1)
	   flag=1;
   if (flag)
   {
      printf("No\n");
      continue;
	}
	else
	{
		if (cnt==0)
		{
		   printf("Yes\n");
		   continue;
		}
	   else
	   {
	      if (s1[p1]==s1[p2]&&s2[p1]==s2[p2])
	      {
	         printf("Yes\n");
	         continue;
			}
			else
			{
			   printf("No\n");
            continue;
			}
		}
	}
}
	return 0;
}