
#include<bits/stdc++.h>
using namespace std ;
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      queue<Node*> q ; 
      vector<int> res ;
      if(node == NULL)
        return res ;
      q.push(node);
      while(!q.empty() )
      {
          Node* val = q.front() ;
          res.push_back(val->data);
          q.pop();
          if(val->left != NULL)
          {
              q.push(val->left);
          }
          if(val->right != NULL)
          {
              q.push(val->right);
          }
          
      }
      return res; 
    }
};