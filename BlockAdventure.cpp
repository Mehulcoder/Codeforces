/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/


#include <bits/stdc++.h>

#include<stdlib.h>
 
using namespace std;


bool isPossible(int* arr, int n, int k, int bag){
	if (n==1)
	{
		return 1;
	}

	
	bag += arr[0] - max(0, arr[1]- k);

	if(bag<0){
		return 0;
	}

	return isPossible(arr+1, n-1, k, bag);


}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	int testcases;

	cin>>testcases;
	while(testcases){
		int n, bag, k;
		cin>>n>>bag>>k;

		int* arr = new int[n];

		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];	
		}
		testcases--;

		if(isPossible(arr, n, k, bag)){
			cout << "YES" << '\n';
		}else{
			cout << "NO" << '\n';
		}

	}

	return 0 ; 

}
