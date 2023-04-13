#include<bits/stdc++.h>
using namespace std ;

// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from S.
// rabbbit
// rabbbit
// rabbbit

// TC : O(m*n) 
// SC : O(m*n) 

class Solution {
public:
    
    int dp[1001][1001];
    
    int fun(string a, string b, int i, int j)
    {
        if(j<0)
            return 1;
        
        if(i<0)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(a[i]==b[j])
            return dp[i][j] = fun(a,b,i-1,j-1)+fun(a,b,i-1,j); 
                            //  Included char   Excluded char
        else
            return dp[i][j] = fun(a,b,i-1,j); 
    }
    
    int numDistinct(string a, string b) 
    {   
        int n = a.size();
        int m = b.size();
        
      memset(dp,-1, sizeof(dp));
        return fun(a,b,n-1,m-1);
    }
};