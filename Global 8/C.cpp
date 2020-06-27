#include<cstdio>
using namespace std;
 
int n;
 
int main() {
	scanf("%d",&n);
	printf("%d\n",n*3+4);
	printf("0 0\n0 1\n1 0\n1 1\n");
	for(int i=1;i<=n;++i) {
		printf("%d %d\n%d %d\n%d %d\n",i,i+1,i+1,i,i+1,i+1);
	}
	return 0;
}