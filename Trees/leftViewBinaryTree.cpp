
#include<bits/stdc++.h>
using namespace std ;

// Method 1 : 
// TC : O( n )
// SC : o( h ) or O( 1 )
vector<int> solve(Node* root , vector<int> &res , int level)
{
    if(root == NULL)
        return res ;
    if(level == res.size() )
    {
        res.push_back(root->data);
    }
    solve(root->left , res , level + 1);
    solve(root->right , res , level + 1);
    return res ;
}

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> res ;
   if(!root)
     return res ;
   return solve(root , res , 0);
}



// Method 2 : Using Map in book 

