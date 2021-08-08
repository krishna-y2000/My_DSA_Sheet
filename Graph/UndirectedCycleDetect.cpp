#include<bits/stdc++.h> 
using namespace std;

// *** DFS *** 

bool isCycleUtil(vector<int> adj[] ,vector<int> vis , int node , int  par)
{
  vis[node] = 1 ;
  for(auto it : adj[node])
  {
    if(!vis[it])
    {
      if(isCycleUtil(adj , vis , it , node) )
        return true ;
    }
    else if(it != par )
      return true ;
  }
  return false ;


}

bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> vis(V , 0);
      for(int i = 0 ; i < V ; i++)
      {
        if(!vis[i])
        {
          if(isCycleUtil(adj , vis , i , -1) )
            return true ;
        }
      }
      return false ;
	}



// **** BFS ****

bool isCycleUtil(vector<int> adj[] ,vector<int> vis , int node)
{

  vis[node] = 1 ;
  queue<pair<int,int>> q ;
  q.push({node ,  -1});
  while(!q.empty())
  {

    int node = q.front().first;
    int par = q.front().second ;
    q.pop();
    for(int val : adj[node])
    {
      if(!vis[val])
      {
        vis[val] = 1 ;
        q.push({val , node});
      }
      else if(val != par )
      {
        return true ;
      }

    }


  }
  return false ;

}

bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> vis(V , 0);
      for(int i = 0 ; i < V ; i++)
      {
        if(!vis[i])
        {
          if(isCycleUtil(adj , vis , i) )
            return true ;
        }
      }
      return false ;
	}