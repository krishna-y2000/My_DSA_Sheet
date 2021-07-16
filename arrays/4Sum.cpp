#include <bits/stdc++.h>
using namespace std;


// Input : 1 1 1 2 2 3 3 4 4 4 

  vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> v ;
        if(arr.empty() || arr.size() < 4 )
            return v ;
        sort(arr.begin() , arr.end() );
        for(int i = 0 ; i < arr.size() - 3 ; i++ )
        {
            for(int j = i + 1 ; j < arr.size() - 2  ; j++ )
            {
               int left = j + 1 , right = arr.size() - 1 ;
               int sum = k - (arr[i] + arr[j] );
               while(left < right )
               {
                   int tempSum = arr[left] + arr[right] ;
                   if(tempSum < sum )   left++ ;
                   else if(tempSum > sum )   right-- ;

                   else
                   {
                       vector<int> tmpV = {arr[i] , arr[j] , arr[left] , arr[right] } ;
                       v.push_back(tmpV) ;
                       while( left < right && arr[left] == arr[left+1 ] ) left++ ;
                       while(left < right && arr[right] == arr[right - 1 ] ) right-- ;
                       left++;
                       right--;

                   }

               }
               while(j+1 < arr.size() && arr[j] == arr[j+1] ) ++j;
               
            }
            while(i+1 < arr.size() && arr[i] == arr[i+1] ) ++i;
        };
        return v ;
    };