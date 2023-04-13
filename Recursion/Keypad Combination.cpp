#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    vector<string> res ;
    
    void solve(string digits , int ind , string current  )
    {
        vector<string>v= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};   
        
        if(ind == digits.length())              
        {
            res.push_back(current);
            return ;
        }
        string codestring = v[digits[ind]-'0' ] ;
        for(int i = 0 ; i < codestring.length() ; i++ )
        {
            solve(digits , ind + 1 , current + codestring[i]   );
            // current + codestring[i]  : Right
            //  codestring[i] + current : Wrong 
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits == "" )
            return {} ;
        solve(digits , 0 , "" );
        return res ;
    }
    
    
  
};