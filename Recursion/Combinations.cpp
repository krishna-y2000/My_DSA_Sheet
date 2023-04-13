#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    
vector<vector<int>> result ;

void solve(int cb, int tb , int limit , vector<int> v  )
{

    if(limit == v.size() )
    {
        result.push_back(v);
        return  ;
    }
    for(int i = cb  ; i < tb + 1 ; i++)       
    {
        v.push_back(i);
        solve(i + 1 , tb ,limit, v  );
        v.pop_back();
        
    }
}

vector<vector<int>> combine(int n, int k) {
    if(n < k )
        return result ;
    vector<int> v ;
    solve( 1 , n ,k , v );
    return result ;
}

};