
#include<bits/stdc++.h>
using namespace std ;

 void dfs(vector<int> &vis ,vector<int> adj[] ,stack<int>& st , int node)
     {
    
         vis[node] = 1 ;
         for(auto val : adj[node])
         {
             if(!vis[val])
               dfs(vis ,adj ,st , val);
         }
         st.push(node);
    
     }
     
    void dfsVis(vector<int>& vis , vector<int> transpose[] ,int node )
    {
        vis[node] =  1 ;
        for(auto val : transpose[node])
        {
            if(!vis[val])
            {
                dfsVis(vis , transpose , val ) ;
            }
        }
    }

 int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> vis(V, 0);
        stack<int> st ;
        for(int i = 0 ; i < V ; i++)
        {
            if(!vis[i])
            {
                dfs(vis ,adj ,st , i);
            }
        }
        vector<int> transpose[V] ;
        for(int i = 0 ; i < V ; i++)
        {
            vis[i] = 0;
            for(auto check : adj[i] )
            {
                transpose[ check ].push_back(i);
            }
        }
        int count = 0 ;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            if(!vis[node])
            {
                count++;
                dfsVis(vis , transpose , node );
            }
            
        }
        return count ;



    }