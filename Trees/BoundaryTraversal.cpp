
#include<bits/stdc++.h>
using namespace std ;

// Method 1 & 2 :

class Solution {
public:

    void solveLeft(Node* root ,vector<int> &v  )
    {
        
        if(root == NULL)
            return ;
        if(root->left != NULL)
    {
        v.push_back(root->data);
        solveLeft(root->left,v);
    }
    else if(root->right != NULL)
    {
        v.push_back(root->data);
        solveLeft(root->right,v);
    }
        
    }
     void solveRight(Node* root ,vector<int>& res  )
    {
        
        if(root == NULL)
            return ;
        if(root->right)
        {
            solveRight(root->right , res);
            res.push_back(root->data);
            
        }
        else if(root->left)
        {
            solveRight(root->left , res);
            res.push_back(root->data);
            
        }
        
    }
    void solveLeaf(Node*root , vector<int> &res  )
    {

        // *** Method 1 ***  Finding leaf from both sub-tree
        if(root == NULL)
            return ;
        solveLeaf(root->left , res);
        if(!(root->left) && !(root->right))
            res.push_back(root->data);
        solveLeaf(root->right , res);

        // *** Method 2 ***  Direct finding leaf from root
         if(!(root->left) && !(root->right))
            {
                res.push_back(root->data);
                return ;
            }
        if(root->left)
            solveLeaf(root->left , res);
        
        if(root->right)
            solveLeaf(root->right , res); 
        
    }

    vector <int> printBoundary(Node *root)
    {
        //Your code here
        vector<int> res ;
        if(!root)
            return res ;
        res.push_back(root->data);
        
        solveLeft(root->left , res);
        // *** Method 1 ***
            solveLeaf(root->left , res);
            solveLeaf(root->right , res);
        // *** Method 2 ***
            solveLeaf(root,res);
        // *** ***
        solveRight(root->right , res);
        return res ;
    }
};



