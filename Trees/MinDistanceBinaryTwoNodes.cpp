
#include<bits/stdc++.h>
using namespace std ;


// TC : O(n)
// SC : O(h)

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
    
    int dist(Node* root , int a , int d )
    {
        if(!root )
            return 0 ;
        if(root->data == a )
            return d ;
        int left =  dist(root->left , a , d + 1);
        int right = dist(root->right , a , d + 1) ;
        if(left != 0 )  // The ans will be in either left or right , so check both
            return left;
        else return right;
        
    }
    
    int findDist(Node* root, int a, int b) {
    // Your code here
    Node* anc = lca(root , a , b);
    int d1 = dist(anc , a , 0);
    int d2 = dist(anc , b , 0);
    return d1 + d2 ;
  
}