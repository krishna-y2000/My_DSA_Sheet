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



// Solution 2 : 

class Solution {
public:
    int maxArea(vector<int>& arr) {
        
        int leftMax = 0, rightMax = 0;
        int i = 0, j = arr.size()-1;
        int res = 0; 
         while(i < j)
        {
            int dist = min(arr[i],arr[j]) * (j-i);
            res = max(dist , res);
            leftMax = max(leftMax, arr[i]);
            rightMax = max(rightMax, arr[j]);
            if(leftMax > rightMax)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return res ; 
    }
};
