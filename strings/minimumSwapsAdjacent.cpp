	
#include <iostream>
using namespace std;
 
// Function to check if strings `X` and `Y` are interleaving of

int minimumNumberOfSwaps(string s){
        // code here 
        int open = 0 , close = 0 , fault = 0 , ans = 0;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == ']' )
            {
                close++;
                fault = close - open ;
            }
            else
            {
                open++;
                if(fault > 0 )
                {
                    ans += fault ;
                    fault-- ;
                }
            }
        }
        return ans ;
};

