#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:


    bool solve(int i , vector<int> nums , int cons , int k , vector<vector<int>> subset , vector<int> sumV)
    {
        if(i  > nums.size() )
        {
            if(cons == k )
            {
                for(int m = 0 ; m < subset.size() ; m++)
                {
                    for(int j = 0 ; j < subset[m].size() ; j++ )
                    {
                        sum += subset[m][j];
                        
                    }
                    if(prevSum == 0 )
                        prevSum = sum   ;
                    else if(prevSum == sum )
                        continue ;
                    else 
                        return false ;
                }
                return true ;
            }
        }

        for(int j = 0 ; j < nums.size() ; j++ )
        {
            if(subset[cons].size() == 0  )
            {
                subset[j].push_back(i);
                sumV[j] += i ;
                solve(i + 1 , nums , cons + 1 , k  , subset , sumV );
                sumV[j] -= i ;
                subset[j].pop_back(i);
                break;
            }
            else
            {
                subset[j].push_back(i );
                solve( i + 1 , nums , cons , k  , subset , sumV);
                subset[j].pop_back(i);
            }
        }

    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end() );
        vector<vector<int>> subset ;
        vector<vector<int>> sumV ;
        return solve(nums[0] , nums , 0 , k  , subset , sumV );
    }
};