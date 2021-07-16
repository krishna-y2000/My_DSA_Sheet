    #include<bits/stdc++.h>
    using namespace std ;
    
    int dp[1001][1001];
    int lcsfinal( int m , int n  , string &s1 , string &s2  )
    {
        if(m== 0 || n ==0 ) return 0 ;
        if(dp[m][n] != -1) return dp[m][n] ;
        
        if(s1[m-1] == s2[n-1] )
        {
            return dp[m][n] = 1 + (lcsfinal(  m-1 , n-1 , s1 , s2) );
        }
        else
        {
            return dp[m][n] = max(lcsfinal( m-1 , n , s1 , s2)  , lcsfinal( m, n-1 , s1 , s2)  ) ;
        }
       // return dp[m][n] ;
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        memset(dp , -1 , sizeof dp) ;
        return lcsfinal( x , y , s1 , s2);
    }