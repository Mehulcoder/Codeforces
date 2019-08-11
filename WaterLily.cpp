#include <iostream>
using namespace std;
#include <iomanip>
#include <cmath>
typedef long double ld;
int main() {
	long long h,l;
	std::cin >> h>>l;
	cout << fixed << setprecision(13);
	
    ld ans;
    ans = ((pow(l,2))-(pow(h,2)))/(ld(2.0*h));
    
    std::cout << ans << std::endl;
	
	
}