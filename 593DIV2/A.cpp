#include <iostream>
using namespace std;
int a,b,c,i,ans,n;
int main() {
    cin>>n;
    while(n--){
        cin>>a>>b>>c;
        cout<<min(b,c/2)*3+min(a,(b-min(b,c/2))/2)*3<<endl;
    }
}
