#include<bits/stdc++.h>
using  namespace std ;

class Solution {
public:

// Method 1 & 2 combine
vector<vector<int>> res ;
void solve(int ind , vector<int> nums   )
{
    if(ind == nums.size() )
    {
        res.emplace_back(nums);                     
    }

    for(int i = ind ; i < nums.size() ; i++ )
    {
        //  Only on duplicate values  nums = [1 ,1 , 2]      //  Method 2  
        // if( i != ind && nums[i] == nums[ind] )  // skip the duplicate
        //  continue ; 
    
        swap(nums[i] , nums[ind] );
        solve(ind + 1 , nums  );
    }
}



vector<vector<int>> permute(vector<int>& nums) {
       
       // sort(nums.begin(),nums.end()); // Mathod 2 step 
       // Sort is used detect the duplicate 
        solve(0 , nums );
        return res ;

    }
};


// Method 1 : No duplicate values
// Input : [1,2,3]
// Output : [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


// Method 2 : Duplicate Values
// Input : [1,1,2]
// Output: [ [1,1,2], [1,2,1], [2,1,1] ]


// Method 3 : 
// Problem solution of Duplicate values using Map
// Choice is made by box

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> curr;
        unordered_map<int, int> counter;
        for (auto x : nums) ++counter[x];
        generatePermutations(counter, curr, output, size(nums));
        return output;
    }
private:
    void generatePermutations(unordered_map<int, int>& counter, vector<int>& curr, vector<vector<int>>& output, int n) {
        if (size(curr) == n) {
            output.emplace_back(curr);
            return;
        }
        for (auto [key, value] : counter) {
            if (value == 0) continue;
            curr.emplace_back(key); --counter[key];
            generatePermutations(counter, curr, output, n);
            curr.pop_back(); ++counter[key];
        }
    }
}; 