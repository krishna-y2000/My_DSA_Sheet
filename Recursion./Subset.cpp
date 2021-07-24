#include<bits/stdc++.h>
using namespace std ;


// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Problem :  Subset with no duplicate 
// Method 1 : 
class Solution {
public:
    vector<vector<int> > result ;

    void helper(vector<int> nums , int ind ,vector<int> current  )
    {
        result.push_back(current);
        for(int i = ind ; i < nums.size() ; i++ )
        {
            current.push_back(nums[i] );
            helper(nums , i + 1 , current);
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v ;
        helper(nums , 0 ,v  );
        return result ;
    }
};
// Method 2 :
    vector<vector<int> > result ;
    void helper(vector<int> nums , int ind ,vector<int> current  )
    {
       if(ind == nums.size() )
       {
           result.push_back(current);
           return ;
       }
       helper(nums , ind + 1 , current ); // No value taken and call
       current.push_back(nums[ind] );     // Value taken and call
       helper(nums , ind + 1 , current);    
     
    }

 vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v ;
        helper(nums , 0 ,v  );
        return result ;
    }

// Problem :  Subset with duplicate 
class Solution {
public:

    set<vector<int> > result ;
    void helper(vector<int> nums , int ind ,vector<int> current  )
    {
        result.insert(current);
        for(int i = ind ; i < nums.size() ; i++ )
        {
            current.push_back(nums[i] );
            helper(nums , i + 1 , current);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v ;
        sort(nums.begin() , nums.end() );
        helper(nums , 0 ,v  );
        vector<vector<int>> ans(result.begin() , result.end() );
        return ans ;
    }
};