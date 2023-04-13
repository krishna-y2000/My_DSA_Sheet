#include<bits/stdc++.h>
using namespace std ;


// TC : O(m*n) 
// SC : O(m*n) 

int dp[501][501];
int solve(string word1 , string word2 , int n , int m   )
{

    if(n == 0 )
        return m ;
    if(m==0)
        return n ;
    if(dp[n][m] != -1 )
    {
        return dp[n][m] ;
    }

    if(word1[n-1] == word2[m-1] )
    {
        dp[n][m] = solve(word1 , word2 , n-1 , m-1 );
    }
    else 
    {
        dp[n][m] = 1 + min(min(solve( word1 , word2 , n-1, m-1 ) ,   // replace 
                               solve(word1 , word2 ,n-1 ,m ) ) ,    // delete 
                               solve(word1 , word2 , n , m-1)  );   // insert 
    }
    return dp[n][m] ;

}

int minDistance(string word1, string word2) {
     
     int  n = word1.size() , m = word2.size();
     memset(dp,-1,sizeof(dp));
     return solve(word1 , word2 , n , m  );

    }