#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:

    bool solve(vector<int> nums , vector<int> visited , int start , int k , int sum , int curr_num , int target   )
    {
        if(k == 1  )
            return true ;
        if(sum > target )   /// Reduces the time complexity 
            return false ;
        if(sum == target && curr_num > 0 )
        {
             return solve(nums , visited , 0 , k - 1 ,  0 , 0 , target );
        }

        for(int i = start ; i < nums.size() ; i++ ) 
        {
            if(!visited[i])
            {
                visited[i] = 1 ;
                if(solve(nums , visited , i + 1 , k ,  sum + nums[i] , curr_num + 1 , target ) )
                    return true ;
                visited[i] = 0;
            }
        }
        return false ;

    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0 ;
        for( int val  : nums)
        {
            sum += val ;
        }
        if(k <= 0 || sum % k != 0 )
            return false ;
        vector<int> visited(nums.size(), 0);
        return solve(nums , visited , 0 , k ,  0 , 0 , sum/k );
    }
};