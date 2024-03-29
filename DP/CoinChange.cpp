
// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1


class Solution {
public:
   
   int solve( vector<int> &coins , int amount ,  int n , int dp[][13] )
   {

       if(n == 0 || amount == 0 )
       {
           return amount == 0 ? 0 : INT_MAX-1 ;
       }
       if(dp[amount][n] != -1 )
          return dp[amount][n];
       if( coins[n-1] <= amount )
       {
           dp[amount][n] = min(1 + solve(coins , amount - coins[n-1] ,n,dp) , solve(coins , amount, n-1 , dp));
       }
       else 
       {
           dp[amount][n] = solve(coins , amount,n-1,dp) ;
       }
       return dp[amount][n] ;
   }
   
   
   int coinChange(vector<int>& coins, int amount) {
       int dp[10001][13] ;
        memset(dp , -1 , sizeof(dp) );
        int minCoins =  solve(coins , amount ,coins.size() , dp ) ;
       return minCoins == INT_MAX - 1 ? -1 : minCoins;   
    }
};