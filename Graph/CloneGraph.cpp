
#include<bits/stdc++.h>
using namespace std ;

 Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> copies;
        if(!node)
            return node;
        
        queue<Node*> q ;
        Node* rootnew = new Node(node->val ,{} );
        copies[node] = rootnew ;
        q.push(node);           
        while(!q.empty())
        {
            Node* temp = q.front() ;
            q.pop();
            for(Node* child : temp->neighbors )
            {
                if(copies.find(child) == copies.end())
                {
                   copies[child] = new Node(child->val , {} );
                    q.push(child);
                    
                }
                copies[temp]->neighbors.push_back(copies[child]);
            }
        }  
        return rootnew ;


    }