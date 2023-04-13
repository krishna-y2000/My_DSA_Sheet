
// Input: nums = [1,3,5,4,7]
// Output: 2
// Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
// Input: nums = [2,2,2,2,2]
// Output: 5

class Solution {
public:
   int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int max_len = 1 ;
        int res = 0  ;
        vector<int> count(n, 1), lis(n, 1);
        for(int i = 1 ; i < n ; i++)
        {
            
            for(int j = 0 ; j < i ; j++)            
            {   
                if( nums[i] > nums[j]  )
                {
                    if( lis[j] + 1 > lis[i] )
                    {
                        lis[i] = lis[j] + 1;
                        count[i] = count[j];
                    }
                    else if( lis[j] + 1 == lis[i] )
                    {
                        count[i] += count[j] ;
                    }
                }
                
            }
          max_len = max(max_len, lis[i]);
        }
       for(int i = 0 ; i < n ; i++)
       {
           if(lis[i] == max_len)
           {
               res += count[i] ;
           }
       }
        
        return res ;
    }
};