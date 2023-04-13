

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

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int dp[1001][1001] ;        //  0 <= a,b <= 1000
        memset(dp,-1,sizeof(dp));
        string res = "";
        lcs(str1 , str2 , n , m , dp);
        while(n > 0 && m > 0 )
        {
            if(str1[n-1] == str2[m-1] )
            {
                res += str1[n-1];
                n-- , m-- ;
            }
            else 
            {
                if(dp[n-1][m] > dp[n][m-1] )
                {
                    res += str1[n-1];
                    n-- ;
                }
                else 
                {
                    res += str2[m-1];
                    m--;
                }
            }
        }
        while( n > 0 )
        {
            res += str1[n-1];
            n--;
        }
        while(m > 0 )
        {
            res += str2[m-1];
            m-- ;
        }
        reverse(res.begin(),res.end()); 
        return res ;
    }
};