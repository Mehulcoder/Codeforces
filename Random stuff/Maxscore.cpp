#include <iostream>
using namespace std;
#include <vector>
#include <iomanip>
#include<cmath>
#include<string>
int main() {
    ios_base::sync_with_stdio(0);
	int m, n;

	cin>>n>>m;
	if(n==0 || m==0){
	    cout<< 0 <<endl;
	    return 0;
	}

	vector<string>v1;
	
	for(int i = 0; i<n; i++){
		string s1;
		cin>>s1;
		v1.push_back(s1);
	}

	vector<long long> w;
	for(int i=0; i<m;i++){
		int p;
		cin>>p;
		w.push_back(p);
	}

	long long sum = 0;
	for(int i = 0; i<m; i++){
		int a = 0;
		int b = 0;
		int c = 0;
		int d = 0;
		int e = 0;

		for(int j = 0; j<n; j++){
			if(v1[j][i]=='A'){
				a++;
			}else if(v1[j][i]=='B'){
				b++;
			}else if(v1[j][i]=='C'){
				c++;
			}else if(v1[j][i]=='D'){
				d++;
			}else if(v1[j][i]=='E'){
				e++;
			}
		}

		long long freq = max(a, max(b,max(c, max(d, e))));
		sum=sum+freq*w.at(i);


	}

	cout << sum << '\n';
	return 0;
}