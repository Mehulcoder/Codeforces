#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	int a,b,c;
	std::cin >> a >> b >> c;
	
	ll* arr= new ll[a];
    for(int i=0;i<a;i++){
        cin>>arr[i];
    }
    
 /*   int* ans=new int[a];
    for(int i=0;i<a;i++){
        ans[i]=0;
    }*/
    
    for (int i=0; i<a; i++) {
        bool notsorainy=1;
        for(int j=1;j<=b;j++){
            if(i-j>=0 && arr[i-j]<=arr[i]){
                notsorainy=0;
                break;
            }
            
            notsorainy=1;
        }
        
        if(notsorainy==1){
        for(int j=1;j<=c;j++){
            if(i+j<a && arr[i+j]<=arr[i]){
                notsorainy=0;
                break;
            }
        }
        }
        
        if(notsorainy==1){
            std::cout << i+1 << std::endl;
            return 0;
        }
    }
    return 0;
}
