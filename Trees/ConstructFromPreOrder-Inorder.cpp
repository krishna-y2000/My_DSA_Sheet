#include<bits/stdc++.h>
using namespace std ;


class Solution{
    public:
    int ind = 0;
    Node* solve(unordered_map<int,int> &mp ,int in[],int pre[], int lb  , int ub  )
    {
        if(lb > ub)
            return NULL ;
        Node* res = new Node(pre[ind++]);
        if(lb == ub )
            return res ;
        
        int mid = mp[res->data] ;
        res->left = solve(mp , in , pre , lb , mid - 1 );
        res->right = solve(mp , in , pre , mid + 1 , ub);
        return res ;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        unordered_map<int,int> mp ;
        for(int i = 0 ; i < n ; i++)
        {
            mp[in[i]] = i ;
        }
        return solve(mp , in , pre , 0 , n-1); 
        
    }
};



// inorder[] = {3 1 4 0 5 2}
// preorder[] = {0 1 3 4 2 5}
// Output: 3 4 1 5 2 0