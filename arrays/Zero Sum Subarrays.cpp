#include<bits/stdc++.h>
using namespace std;
#define ll long long


class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        ll sum = 0 , tempSum = 0;
        unordered_map<int , int> mp ;
        mp[0] = 1 ;
        for(int i = 0 ;i < n ; i++)
        {
            tempSum += arr[i];
            if(mp.find(tempSum ) != mp.end() )
            {
                sum += mp[tempSum] ;
                mp[tempSum]++;
            }
            else 
                mp[tempSum]++;
        }
        return sum ;
    }
};


// 6
// 0 0 5 5 0 0

// 6