#include<bits/stdc++.h>
using namespace std ;

// Method 1 :  Swapping nodes from leaf node
 // TC : O( n )
 // SC : If we don’t consider size of stack for function
 //     calls then O(1) otherwise O(h) where h is the height of the tree. 

treenode* mirrorTree(node* root)
{
	// Base Case
	if(!root)
      return NULL;
    node* left = mirrorTree(root->left);
    node* right = mirrorTree(root->right);
    node* t = left ;
    root->left = right ;
    root->right = t ;
    return root ;
}

// Method 2 : Swapping nodes from root node

treenode* mirrorTree(node* root)
{
    // Base Case
    if (root == NULL)
        return root;
    node* t = root->left;
    root->left = root->right;
    root->right = t;
 
    if (root->left)
        mirrorTree(root->left);
    if (root->right)
        mirrorTree(root->right);
   
  return root;
}
