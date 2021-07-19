#include<bits/stdc++.h>
using namespace std ;


int solve(int n , int k )
{
    if(n == 1 )
    {
        return 0 ;
    }
    int x = solve(n-1 , k);
    int y = (x + k ) % n ;
    return y ;
}


// n = 4 , k = 3
// 0 1 2 3 0 1
//       0 1 2 0 1 
//             0 1 1
//                 0