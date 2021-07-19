#include<bits/stdc++.h>
using namespace std ;


// 1) Find string of k length combination
// Calculate nCr ; r = k ;

// Choice is made by char
vector<string> res ;
void solve(int i  , string ustring , int ssf , int k , string asf )
{
    if( i == ustring.size() )
    {
        if(ssf == k )
        {
            res.push_back(asf);
        }
        return ;
    }

    
    solve(i + 1 , ustring , ssf + 1 , k , asf + ustring[i] ); // Select the char 
    solve(i + 1 , ustring , ssf + 0 , k , asf + ""  );        // Does not select the char 
}




// 2)  k length selection from distict character abc - {  }
// Method 2 : 

// Choice is made by box( index of string ) of which char to choose
vector<string> res ;
void solve(int cb, string ustring , int k , vector<string>  current )
{

    if(cb == k )
    {
        result.push_back(current);
        return  ;
    }
    for(int i = cb  ; i < ustring.size() ; i++)
    {
        current.push_back(ustring[i]);
        solve(i + 1 , ustring ,k , current );
        current.pop_back();
        
    }
}


// ustring : [a ,b , c ] 
// Result : [ ab , ac , bc ]

