
#include<bits/stdc++.h>
using namespace std ;

struct bst
{
    bool isBST ;
    int size ;
    int min ;
    int max ;
};

bst check(Node* root)
{
    if(!root)
    {
        bst b = {true ,0, INT_MAX , INT_MIN };
        return b ;
    }
    bst left = check(root->left);
    bst right = check(root->right); 
    // For node 
    if(left.isBST && right.isBST && left.max < root->data && right.min > root->data )
    {
        bst b = { true , 1 + left.size + right.size , min(root->data , left.min) ,
                max(root->data , right.max) };
        return b ;
    }
    // If not bst
    bst b = { false , max(left.size , right.size ) , -1 , -1  };
    return b;
}

int largestBst(Node *root)
{
	//Your code here
	bst x = check(root);
	return x.size;
}