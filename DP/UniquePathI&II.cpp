

// 1) Unique Path 1 

// Input: m = 3, n = 2
// Output: 3

class Solution {
public:
 int solve(int m , int n , int dp[][101] )
 {
     if(m < 0 || n < 0  )
     {
         return 0 ;
     }
     if( m == 0 || n == 0 )
        return 1 ;
    if(dp[m][n] != -1 )
        return dp[m][n] ;
     dp[m][n] = solve( m-1 , n , dp) + solve(m , n-1 , dp) ;
     return dp[m][n] ;
 }
 
 int uniquePaths(int m, int n) {
        int dp[101][101] ;
        memset(dp , -1 , sizeof(dp));
        return solve(m-1 , n-1 , dp );       
    }
};

// Method 2 : 
int dp[101][101]{};
int uniquePaths(int m, int n, int i = 0, int j = 0) {
    if(i >= m || j >= n) return 0;
    if(i == m-1 && j == n-1) return 1;
    if(dp[i][j]) return dp[i][j];
    return dp[i][j] = uniquePaths(m, n, i+1, j) + uniquePaths(m, n, i, j+1);
}



// 2) Unique path 2 

// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2

class Solution {
public:
    int solve(int m , int n , int dp[][101], vector<vector<int>>& obstacleGrid )
 {
     if(m < 0 || n < 0 || obstacleGrid[m][n] == 1  )
     {
         return 0 ;
     }
     if( m == 0 && n == 0 && obstacleGrid[m][n] == 0  ) // change here 
        return 1 ;
    if(dp[m][n] != -1 )
        return dp[m][n] ;
     
     dp[m][n] = solve( m-1 , n , dp , obstacleGrid ) + solve(m , n-1 , dp , obstacleGrid ) ;
     return dp[m][n] ;
 }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp[101][101] ;
        int m = obstacleGrid.size() , n = obstacleGrid[0].size() ;
        memset(dp , -1 , sizeof(dp));
        return solve(m-1 , n-1 , dp , obstacleGrid );  
    }
};