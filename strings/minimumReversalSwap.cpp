	
#include <iostream>
using namespace std;
int countRev (string s)
{
    // your code here
    if(s.size() & 1 == 0 )
    {
        return -1 ;
        
    }
    int ans , count = 0 ;
    for(int i = 0 ; i < s.size() ; i++ )
    {
        if(s[i] == '{')
        {
            count++;
        }
        else
        {
            if(!count)
            {
                ans++;
                count++;
            }
            else
            {
                count--;
            }
        }
    }
    return ans + count/2 ;
}