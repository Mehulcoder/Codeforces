#include <iostream>
using namespace std;
#include<cmath>
#include <unordered_map>
#include<algorithm>
#include <bits/stdc++.h>
long long maxSum(long long arr[], int n, int k) 
{ 
    // n must be greater 
    if (n < k) 
    { 
       cout << "Invalid"; 
       return -1; 
    } 
  
    // Compute sum of first window of size k 
    long long res = 0; 
    for (int i=0; i<k; i++) 
       res += arr[i]; 
  
    // Compute sums of remaining windows by 
    // removing first element of previous 
    // window and adding last element of  
    // current window. 
    long long curr_sum = res; 
    for (int i=k; i<n; i++) 
    { 
       curr_sum += arr[i] - arr[i-k]; 
       res = max(res, curr_sum); 
    } 
  
    return res; 
} 
  
class data
{
    public:
    long long data;
    int frequency;
};
int main() {
    long long n,l;
    std::cin >> n>>l;
    long long* arr=new long long [n];
    long long maxmemory=8*l;
    if(l==0){
        return 0;
    }
    
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    
    
    
    unordered_map<long long, int> m1;
    
    for (int i = 0; i < n; i++) {
        m1[arr[i]]++;
    }
    
    int totaldistinct=m1.size();
    
    long long currentmemory;
    currentmemory=n*ceil(log2(totaldistinct));
    
    
    int maxpossibledisctinct;
    maxpossibledisctinct=pow(2,floor(double(maxmemory)/n));
    
    
    int rem=totaldistinct-maxpossibledisctinct;
    if(rem<=0){
        std::cout << 0 << std::endl;
        return 0;
    }
    
  //  std::cout << maxpossibledisctinct << std::endl;
 //   std::cout <<"max "<<maxpossibledisctinct << std::endl;
   // std::cout << "current " <<totaldistinct<< std::endl;
//    std::cout << "remove " <<totaldistinct-maxpossibledisctinct<< std::endl;
    
    sort(arr,arr+n);
    
    
    
    data* box=new data [totaldistinct];
    
    int j=0;
    for (int i = 0; i < n;) {
        
        box[j].data=arr[i];
        box[j].frequency=m1[box[j].data];
        i=i+box[j].frequency;
        j++;
    }
    long long* freq = new long long [totaldistinct];
    for (int i = 0; i < totaldistinct; i++) {
        freq[i]=box[i].frequency;
    }
    
   long long ans=maxSum(freq, totaldistinct, totaldistinct-rem);
   int sum=0;
   for(int i=0;i<totaldistinct;i++){
       sum=sum+freq[i];
   }
   
   cout<< sum-ans;
   delete [] box;
   delete [] freq;
   delete [] arr;
   return 0;
    
    
    
    
}