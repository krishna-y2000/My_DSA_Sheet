
#include<bits/stdc++.h>
using namespace std ;

// Case 1: Node to be deleted is the leaf
// Case 2: Node to be deleted has only one child
// Case 3: Node to be deleted has two children

    struct TreeNode* minValueNode(struct TreeNode* node)
    {
        struct TreeNode* current = node;

        /* loop down to find the leftmost leaf */
        while (current && current->left != NULL)
            current = current->left;

        return current;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root ;
        if(root->val < key)
        {
            root->right = deleteNode(root->right , key);
        }
        else if(root->val > key)
        {
            root->left = deleteNode(root->left , key);
        }
        else 
        {
            if(!root->left )
            {
                TreeNode* temp = root->right ;
                delete(root);
                return temp ;
            }
            if(!root->right )
            {
                TreeNode* temp = root->left ;
                delete(root);
                return temp ;
            }
            TreeNode* small = minValueNode(root->right );
            root->val = small->val;
            
            root->right = deleteNode(root->right , small->val);
            
            
        }
        return root;
        
    }