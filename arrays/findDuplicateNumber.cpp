
#include <bits/stdc++.h>
using namespace std;

// Input : 1 3 5 2 2 
// Output : 2

// Method - 1
int findDuplicate(vector<int>& nums) {
        
        // O(N) solution 
        sort(nums.begin() , nums.end() );
        for(int i = 1 ; i < nums.size() ; i++ )
        {
            if(nums[i] == nums[i-1] )
            {
                return nums[i];
            }
        }
        return -1 ;
    }

// Method - 2
int findDuplicate(vector<int>& nums) {
      if(nums.size() > 1 )  
      {
        int slow = nums[0] ;
        int fast = nums[nums[0]];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0 ;
        while(fast != slow )
        {
            slow = nums[slow];
            fast = nums[fast];
        }  
        return slow ;
      }
      return -1 ;
    }
}

// Method 3 : 
// Using Binary Search with Pigeonhole Principle 
int findDuplicate(vector<int>& nums)
{
    int left = 0 , right = nums.size();
    // left = 1 , right = nums.size() - 1 ;
    while(left < right )
    {
        int mid = left + (right - left) / 2 ;
        int count = 0 ; 
        for( int it : nums )
        {
            if( it <= mid  )
                count++;
        }
        if(count <= mid )   left = mid + 1 ;
        else right = mid ;
    }
    return left ; 
}