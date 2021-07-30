#include<bits/stdc++.h>
using namespace std ;

// NOTE : Inorder Traversal of BST is always in ascending order

    void inorder(Node* root , vector<int> &v)
    {
        if(!root)
            return ;
        inorder(root->left , v);
        v.push_back(root->data);
        inorder(root->right , v);
        
    }
    int i = 0;
    void inorderChange(Node* root , vector<int> v  )
    {
        if(!root)
            return ;
        inorderChange(root->left , v );
        root->data = v[i++] ;
        inorderChange(root->right , v );
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int> v ;
        inorder(root , v);
        sort(v.begin() , v.end() );
        inorderChange(root , v );
        return root ;
    }