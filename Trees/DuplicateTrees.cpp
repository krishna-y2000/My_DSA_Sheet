#include<bits/stdc++.h>
using namespace std ;


unordered_map<string, int>trees;
vector<Node*>ans;

string helper(Node* root){
  
  if(!root){
    return "$";   // differential from btw two strings 
  }
  string str = "";
  string left=helper(root->left) ;
  string right=helper(root->right) ;
  str += left + right + to_string(root->data);
  trees[str]++ ;
  if(trees[str]==2){
    ans.push_back(root);
  }
  return str;
}

vector<Node*>printAllDups(Node* root){
  trees.clear();
  ans.clear();
  string waste=helper(root);
  return ans;
}