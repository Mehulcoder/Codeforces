/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/


#include <bits/stdc++.h>

using namespace std;


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin>>n;
	string events;
	cin>>events;

	
	int arr[10];
	for (int i = 0; i < 10; ++i)
	{
		arr[i] = 0;
	}


	for (int i = 0; i < n; ++i)
	{
		if (events[i]=='L')
		{
			int left = 0;
			while(arr[left]==1 && left<9){
				left++;
			}
			arr[left] = 1;
			continue;

		}else if (events[i] == 'R')
		{
			int right = 9;

			while(arr[right]==1 && right>0){
				right--;
			}
			arr[right] = 1;
			continue;

		}else
		{
			int room  = int(events[i])-48;
			arr[room] = 0;
		}
	}
	
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i];
	}
		cout <<'\n';


	return 0 ; 



}
