
#include<bits/stdc++.h>
using namespace std ;

// TC : O(m*n) 
// SC : O(m*n) 


class Solution {
public:

int lcs(string &text1, string &text2 , int n , int m ,int dp[][1001])
{
    if(n == 0 || m == 0 )
        return 0 ;
    if(dp[n][m] != -1 )
        return  dp[n][m];

    if(text1[n-1] == text2[m-1])
    {
  return dp[n][m] = 1 + lcs(text1 , text2 , n-1 , m-1 ,dp);
    }
    else 
    {
   return dp[n][m] = max(lcs(text1 , text2 , n , m-1,dp)  , lcs(text1 , text2 , n-1 , m,dp) ) ;
    }
   
}

  int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int dp[1001][1001] ;        //  0 <= a,b <= 1000
        memset(dp,-1,sizeof(dp));
        return lcs(text1 , text2 , n , m , dp);
    }

};