
#include<bits/stdc++.h>
using namespace std ;

int solve(Node *root)
    {
       if(!root)
        return 0 ;
        
        int val = root->data ;
        int left = solve(root->left) ;
        int right = solve(root->right);
        root->data = left + right ;
        return root->data + val ;
    }
    
    
    void toSumTree(Node *node)
    {
        // Your code here
        int left = solve(node->left) ;
        int right = solve(node->right);
        node->data = left + right ;
    }