
#include<bits/stdc++.h>
using namespace std ;

    void solveLeft(Node* root , vector<int> &v1  )
    {
        if(!root)
            return ;
        if(!root->left && !root->right )
        {
             v1.push_back(root->data) ;
             return;
        }
        solveLeft(root->left , v1);
        solveRight(root->right , v1);

    }
    void solveRight(Node* root , vector<int> &v2  )
    {
        if(!root)
            return ;
        if(!root->left && !root->right )
        {
             v2.push_back(root->data) ;
             return;
        }
        solveLeft(root->left , v2);
        solveRight(root->right , v2);
    }

    int dupSub(Node *root)
    {
         // code here
        vector<int> v1 ;
        vector<int> v2 ;
        solveLeft(root->left , v1 );
        solveRight(root->right , v2);
        if(v1.size() >= 2 && v2.size()>= 2 )
        {
            for(int i = 0 ; i < v1.size() ; i++)
            {
                if(v1[i] == v2[i])
                    continue ;
                else return 0 ;
            }
            return 1 ; 
        }
        else return 0 ;
       
    }