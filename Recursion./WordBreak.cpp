
#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
   

    bool helper(const string& s, int start, const unordered_set<string>& d, vector<int>& memo) {
        if (start == s.size()) {
            return true;
        }
        
        if (memo[start] != -1) return memo[start];
        
        for (int i = start + 1; i <= s.size(); ++i) {
            const string sub = s.substr(start, i - start); 
            if (d.count(sub) == 1 && helper(s , i , d , memo) ) {
                    memo[start] = 1;
                    return true;
            }
        }
        
        memo[start] = 0;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> d(wordDict.begin(), wordDict.end());
		// Use a vector since we can index from 0 to N. 
		// Possible values in vector are: -1, 0, 1.
        vector<int> memo(s.length(), -1); 
        return helper(s, 0, d, memo);
    }
};