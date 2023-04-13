

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3


// Method 1 : similar to SubsetSum method -> 0/1 knapsack 
class Solution {
public:
   int helper(vector<int>& nums,int target,int n,int index,int sum , vector<vector<int>>& dp){
        if(index==n){
            if(sum==target){
                return 1;
            }
            return 0;
        }
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        return dp[index][sum]= helper(nums,target,n,index+1,sum+nums[index], dp) + helper(nums,target,n,index+1,sum,dp);
    }

  int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if((sum-target)%2!=0){
            return 0;
        }
        int newTarget = (sum-target)/2;
         vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,-1));
        
        return helper(nums,newTarget,n,0,0,dp);
    }
};



// Method 2 : 


   int count = 0 ;
    void solve(vector<int>& nums , int target , int sum , int n)
    {
        if( n == 0 )
        {
            if( target == sum )
                count++ ;
            return ;
        }
        
        solve( nums , target , nums[n-1] + sum , n-1 );
        solve( nums , target , -nums[n-1] + sum , n-1 );
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        solve( nums , target , 0 , nums.size() );
        return count ;
    }