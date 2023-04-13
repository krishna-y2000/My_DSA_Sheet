#include<bits/stdc++.h>
using namespace std ;


// Method 1 : Use just faith and handle base case smartly
// sr = 1 , sc = 1 , dr = 3 , dc = 3 , ans = ""

void findMazePaths(int sr , int sc , int dr , int dc , string ans ) 
{
    if(sr > dr || sc > dc )
        return ;
    if(sr == dr && sc == dc  )
    {
        cout << ans << "\n" ;
        return ;
    }
    findMazePaths(sr , sc+1 , dr ,dc , ans + "h" );
    findMazePaths(sr + 1 , sc , dr , dc , ans  + "v");
}


//Method 2 : 
// Use expected and faith technique :- Big problem from smaller problem 


int findMazePaths(int sr , int sc , int dr , int dc , string ans   ) 
{
    if(sr > dr || sc > dc )
        return 0;
    if(sr == dr && sr == dc  )
    {
       return ans ;
    }
    return findMazePaths(sr , sc+1 , dr ,dc , ans + 1 ) + findMazePaths(sr + 1 , sc , dr , dc , ans  + 1);
}