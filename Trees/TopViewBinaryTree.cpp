
#include<bits/stdc++.h>
using namespace std ;

 void solve(Node* root , int level , int dist , map<int , pair<int,int> > &mp   )
    {
        if(root == NULL)
            return ;
    
        if(mp.find(dist) == mp.end() )
        {
            mp[dist] = make_pair(root->data , level) ;
        }
        else if(mp[dist].second > level  )
        {
            mp[dist] = make_pair(root->data , level);
        }
        
        solve(root->left ,  level + 1 ,dist - 1 ,  mp);
        solve(root->right , level + 1 ,dist + 1 ,  mp);
    }
    
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<pair<int ,int >> res ;
        vector<int> result ;
        map<int , pair<int,int> > mp ;
        solve(root , 0 , 0 , mp);
        for(auto itr = mp.begin() ; itr != mp.end() ; itr++ )
        {
            result.push_back(itr->second.first );
        }
        
        return result ;
    }
