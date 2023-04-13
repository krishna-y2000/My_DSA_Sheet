
// Input: nums = [3,1,5,8]
// Output: 167
// Explanation:
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

class Solution {                                                                                
public:
      int solve(int dp[][503] , vector<int> &numstemp , int left , int right  )
   {

        if(left + 1 == right)
            return 0 ;
        if(dp[left][right] != -1 )
            return dp[left][right] ;
        int ans = INT_MIN ;
       for(int i = left + 1 ; i < right ; i++)
       {
           int a1 = solve(dp , numstemp , left, i ) ;
           int a2 = solve(dp , numstemp , i , right ) ;
           ans = max( ans , numstemp[left] * numstemp[i] * numstemp[right] + a1 + a2 );
           
       }
       dp[left][right] = ans ;
       return ans ;
   }
   
   int maxCoins(vector<int>& nums) {
    vector<int> numsarray(nums.size() + 2 );
    int n = 1;
    for (int x : nums) numsarray[n++] = x;
    numsarray[0] = numsarray[n] = 1;
    // now n is the last index 
    
    int dp[503][503] ;
    memset(dp , -1 , sizeof(dp));
    return solve(dp, numsarray, 0, n );  
    }
};