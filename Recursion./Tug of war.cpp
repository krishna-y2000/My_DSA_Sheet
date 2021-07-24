#include<bits/stdc++.h>
using namespace std ;



// Minimum Subset Sum Difference Explained : Pepcoding

int min = MAX_VALUE ;
vector<vector<int>> ans ;

void solve(vector<int> s1 , vector<int> s2 , int arr[] , int n ,int ind , int sum1 , int sum2  )
{

    if(ind == n )
    {
        int currentSum = abs(sum1 - sum2);
        if(min > currentSum )
        {
            min = currentSum ;
            ans.push_back(s1 );
            ans.push_back(s2);
        }
        return ;
    }

    if(s1.size() < (n+1) / 2 )
    {
        s1.push_back(arr[ind] );
        solve(s1 , s2 , arr , n , ind + 1 , sum1 + arr[ind] , sum2 );
        s1.pop_back();
    }
    
    else if(s2.size() < (n+1)/2 )
    {
        s2.push_back(arr[ind] );
        solve(s1 , s2 , arr , n , ind + 1 , sum2 + arr[ind] , sum2 );
        s2.pop_back();
    }
    

}