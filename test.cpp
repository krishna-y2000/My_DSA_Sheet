	
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
// Function to check if strings `X` and `Y` are interleaving of

class Solution {
public:

    bool valid(string s , int i , int j , int k)
    {
        return !s.empty() && s.size() <= 3 && stoi(s) <= 255 && (s[0] != '0' || s.size() == 1);
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        for(int i = 0 ; i < n - 3 ; i++)
            for(int j = i + 1 ; j< n-2 ; j++)
            {
                for(int k = j + 1 ; k < n-1 ; k++)
                {
                    if(valid(s,i,j,k) )
                       res.push_back( s.substr(0,i) + "." + s.substr(i,j) + "."+ s.substr(i+j , k) + "." +s.substr(i+j+k) );
                }
            }
    }
};


int main()
{
    string str = "axxxy"; 
    cout << "234";
   // cout << LongestRepeatingSubsequence(str);
    return 0;
}