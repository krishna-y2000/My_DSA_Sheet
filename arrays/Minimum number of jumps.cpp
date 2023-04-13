#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
 int minJumps(int arr[], int n){
        // Your code here
        int  jump = 0 , reach = 0 , end = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            reach = max(reach , i + arr[i] );
            if(i == end)
            {
                jump++;
                end = reach ;
            }
            if(end >= n-1 )
            {
                break ;
            }
           
        }
        if(end < n-1 )
            return -1 ;
        return jump ;
        
    }
};
