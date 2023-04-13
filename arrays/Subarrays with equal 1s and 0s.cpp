#include<bits/stdc++.h>
using namespace std ;


class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
         unordered_map<int,int> hashmap;
        int sum=0,count=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0)
                arr[i]=-1;
        }
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0)
                count++;
            if(hashmap[sum])
                count+=hashmap[sum];
            hashmap[sum]++;   
        }
        return count;
    }
};

