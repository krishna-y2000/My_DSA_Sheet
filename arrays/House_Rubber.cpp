
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.


// Method 1 : 
public int rob(int[] nums , n ) {
    return solve(nums, n - 1);
}

private int solve( int[] nums , int t )
{
    if( n < 0 )
        return 0 ;
    return max( nums[t] + solve(nums , n-2  ) , solve(nums , n-1) );
}


// Method 2 : JAVA Solution 
public int rob(int[] nums) {
    if (nums.length == 0) return 0;
    int[] memo = new int[nums.length + 1];
    memo[0] = 0;
    memo[1] = nums[0];
    for (int i = 1; i < nums.length; i++) {
        int val = nums[i];
        memo[i+1] = Math.max(memo[i], memo[i-1] + val);
    }
    return memo[nums.length];
}