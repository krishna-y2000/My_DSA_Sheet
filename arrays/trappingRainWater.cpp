#include <bits/stdc++.h>
using namespace std;

 int trappingWater(int arr[], int n){
        // Code here
         int leftMax = 0, rightMax = 0;
        int left = 0, right = n-1;
        int total = 0; /// use long long here if return type is long long 
        while(left < right)
        {
        
            leftMax = max(leftMax, arr[left]);
            rightMax = max(rightMax, arr[right]);
            if(leftMax > rightMax)
            {
                total += rightMax - arr[right];
                right--;
            }
            else
            {
                total += leftMax - arr[left];
                left++;
            }
        }
        return total;
    }


