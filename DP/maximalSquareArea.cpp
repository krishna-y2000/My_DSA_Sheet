
// Input : 
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0

// Output : 4


  int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() ;
        int dp[m][n] ;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++ )
            {
                if(i == 0 || j == 0 || matrix[i][j] == '0')
                {
                    dp[i][j] = matrix[i][j] - '0' ;
                }
                else
                {
                    dp[i][j] = min( dp[i-1][j-1] , min( dp[i-1][j] , dp[i][j-1] ) ) + 1;
                }
                ans = max(ans , dp[i][j]);
            }
        }   
        return ans * ans ; 
    }