#include<bits/stdc++.h>
using namespace std ;
/* structure for a Node */

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Input : nums = [1,3] target = 3 
// Output : 1 

int search(vector<int>& nums, int target) {
            int n = nums.size();
        int left = 0 , right = n - 1 , mid = -1 ;
        // find smallest element at left == right 
        while(left < right )
        {
            mid = ( left + right ) / 2 ;
            if( nums[mid] > nums[right] )
                left = mid + 1 ;
            else 
                right = mid ;
        }
        int root = left ; // root is the smallest element 
        left = 0 , right = n - 1 ;
        while(left <= right )
        {
            mid = (left + right) / 2 ;
            int realmid = (root + mid ) % n ;
            if(nums[realmid] == target  ) return realmid ;
            else if(nums[realmid] > target )
            {
                right = mid - 1 ;
            }
            else 
                left = mid + 1 ;
        }
        return -1 ;
        }

// Method 2 : 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0 )   return -1 ; 
        int low = 0 , high = nums.size() - 1 ;
        while(low <= high)
        {
            int mid = low + (high - low ) / 2; 
            if(nums[mid] == target) return mid ;
            
            if(nums[low] <= nums[mid] )
            {
                if(target >= nums[low] && target < nums[mid] )
                {
                    high = mid - 1 ;
                }
                else 
                {
                    low = mid + 1 ;
                }
            }
            else 
            {
                if(nums[mid] < target && target <= nums[high])
                {
                    low = mid + 1 ;
                }
                else 
                    high = mid - 1 ; 
            }
            
           
        }
        return -1 ;
        
    }
};