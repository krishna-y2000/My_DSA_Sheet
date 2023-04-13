

// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7

class Solution {
public:

int solve(vector<vector<int>>& cost , int m , int n ,int memo[][1001] )
{
      if (n < 0 || m < 0) 
         return INT_MAX; 
      else if(m==0 && n==0) 
         return cost[m][n]; 
      if(memo[m][n]!=-1)
          return memo[m][n];
      return  memo[m][n] = cost[m][n]+min(solve(cost,m-1,n,memo),solve(cost,m,n-1,memo));
       
}

 int minPathSum(vector<vector<int>>& grid) {
       int m = grid.size() ;
       int n = grid[0].size() ;
       int dp[1001][1001];
       memset( dp , -1 , sizeof(dp) );
        return solve( grid , m-1 , n-1 , dp ) ;
    }
};