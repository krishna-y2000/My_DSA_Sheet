
#include<bits/stdc++.h>
using namespace std ;

  bool solve(Node* root , int min , int max)
    {
        if(!root)
            return true ;
        if(root->data <= min || root->data >= max  )
            return false ;
        bool left = solve(root->left , min , root->data);
        bool right = solve(root->right , root->data , max);
        return left && right ;
    }
    bool isBST(Node* root) 
    {
        // Your code her
       return solve(root  , INT_MIN ,INT_MAX );
        
    }