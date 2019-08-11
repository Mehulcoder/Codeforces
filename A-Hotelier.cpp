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

	int left = 0, right = 9;
	int arr[10];
	for (int i = 0; i < 10; ++i)
	{
		arr[i] = 0;
	}


	for (int i = 0; i < n; ++i)
	{
		if (events[i]=='L')
		{
			arr[left] = 1;
			
			while(arr[left]!=0 && left<n){
				left++;
			}

		}else if (events[i] == 'R')
		{
			arr[right] = 1;

			while(arr[right]!=0 && right>=0){
				right--;
			}

		}else
		{
			int room  = int(events[i])-48;
			//cout << "My boy"<< room << '\n';
			arr[room] = 0;
			if (abs(left-room)<=abs(right-room))
			{
				if(left>room){
				left = room;
			}
			}else{
				if(right<room){
				right = room;
			}
			}
		}
	}
	//cout <<"left "<<left  << '\n';
	//cout <<"right "<<right  << '\n';
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i];
	}
	//	cout <<'\n';


	return 0 ; 



}
