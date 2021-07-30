
#include<bits/stdc++.h>
using namespace std ;

// Same solution for both LCA in binary tree and LCA in BST

 Node* lca(Node* root ,int n1 ,int n2  )
    {
       //Your code here 
       if(!root)    
            return NULL ;        
        if(root->data == n1 || root->data == n2 )
        {
           return root ;
        }
        Node* left = lca(root->left , n1 , n2 );
        Node* right = lca(root->right , n1 , n2  );
        if(left && right )
            return root ;
        return (left != NULL) ? left : right ;
    }


Case 1 : On different sub-tree
n1 = 2 n2 = 3
1 2 3
Case 2 : On same sub-tree 
n1 = 4 n2 = 6 
1 2 3 4 5 N N N N 6 N 


// Method 2 : For BST only

Node* LCA(Node *root, int n1, int n2)
{
if(root==NULL) return NULL;

if(n1>root->data && n2>root->data)
return LCA(root->right,n1,n2);

if(n1<root->data && n2< root->data)
return LCA(root->left,n1,n2);

return root;
}