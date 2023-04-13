
// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0

// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.


// TC : O(n^2)
class Solution {
public:
   vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        if(n==0)
            return ans;
        
        sort(nums.begin(),nums.end());
        int max = 0;
        vector<int> dp(n+1,1);
        vector<int> previous(n+1,-1); 
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i])
                {
                    dp[i] = 1+dp[j];
                    previous[i] = j ; // keep track of previous change index 
                    
                }
            }
            if(dp[max]<dp[i])
                max = i;
        }
        
        int t = max ;
        while(t >= 0 )
        {
            ans.push_back(nums[t]);
            t = previous[t];
        }
        return ans ;
    }
};