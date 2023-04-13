#include<bits/stdc++.h>
using namespace std ;


// We need to jump from 1, 1 to any steps in horizontal and vertical

void findMazePaths(int sr , int sc , int dr , int dc , string ans ) 
{
    if(sc == dc && sr == dr )
    {
        cout << ans << "\n" ;
        return ;
    }
    for(int ms = 1 ; ms <= dc-sc ; ms++ )
    {
        findMazePaths(sr , sc+ms , dr ,dc , ans + "h" );
    }
    for(int ms = 1 ; ms <= dr - sr ; ms++ )
    {
        findMazePaths(sr + ms , sc , dr ,dc , ans + "v" );
    }

    for(int ms = 1 ; ms <= dc - sc && ms <= dr - sr ; ms++)
    {
        findMazePaths(sr + ms , sc + ms , dr , dc , ans  + "d");

    }
}