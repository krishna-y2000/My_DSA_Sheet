#include<bits/stdc++.h>
using namespace std ;

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]

class Solution {
public:
     void solve( int ind , vector<int>& candidates, int target ,
                vector<vector<int>> &ans, vector<int> &current)
    {
        if(ind == candidates.size())
        {
            if(target == 0 )
            {
                ans.push_back(current);
            }
            return ;
        }

        if( candidates[ind] <= target )
        {
            current.push_back(candidates[ind]);
            solve(ind , candidates , target - candidates[ind] , ans , current); 
            current.pop_back();
        }

        solve(ind + 1  , candidates , target , ans , current); 

    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans ;
        vector<int> current ;
        solve(0 , candidates , target , ans , current); 
        return ans ;

    }
};