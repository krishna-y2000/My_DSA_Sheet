 #include<bits/stdc++.h>
using namespace std ;

 string solve( unordered_map< string , int> &mp , Node* root )
  {
      
      if(!root )
        return "";
      string left = solve(mp , root->left);
      string right = solve(mp ,root->right );
      mp[left + root->data + right]++ ;
      return left + root->data + right ;
      
  }
    
  int dupSub(Node* root)
  {
      unordered_map<string , int> mp ;
      solve(mp , root );
      for(auto curr : mp)
      {
          if(curr.first.size() > 1 && curr.second > 1 )
                return true ;
      }
      return false ;
  }