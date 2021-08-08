#include<bits/stdc++.h>
using namespace std ;


// Method 1 : Using DFS

class Solution {
public:
  bool isCycle(int node ,  int visited[] ,  int dfsVisited[] ,unordered_map<int, vector<int>>& um )
{

    visited[node] = 1 ;
    dfsVisited[node] = 1 ;

    for(auto child : um[node])
    {
        if(!visited[child])
        {
            if(isCycle(child , visited , dfsVisited , um) )
                return true ;
        }
        else if(dfsVisited[child] )  // child is visited already
        {
            return true ;
        }
    }
    dfsVisited[node] = 0 ;
    return false ;

}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> um;
        for (auto p: prerequisites)
        {
            um[p[0]].push_back(p[1]);
        }
        int visited[numCourses], dfsVisited[numCourses]; 
	   memset(visited, 0, sizeof visited); 
	   memset(dfsVisited, 0, sizeof dfsVisited); 

        for(int i = 0 ; i < numCourses ; i++ )
        {
            if(!visited[i] )
            {
                if(isCycle( i , visited , dfsVisited , um) )
                    return false ;
            }
        }
        return true ;

    }
};



// Method 2 : Using BFS - Topological sort using Kahn's Algorithm
// If all nodes are visited so there is no cycle 

bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    
    unordered_map<int, vector<int>> um;
    for (auto p: prerequisites)
    {
        um[p[0]].push_back(p[1]);
    }

    // Calculating indegree
    vector<int> indegree(numCourses, 0);
    for(int  i = 0 ; i < numCourses ; i++)
    {
        for(auto itr : um[i])
        {
            indegree[itr]++;
        }
    }

    //inserting in queue having 0 indegree 
    queue<int> q ;
    for(int  i = 0 ; i < numCourses ; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    int count = 0;
    while(!q.empty())
    {
        int val = q.front();
        q.pop();
        count++;
        for(auto itr : um[val])
        {
            indegree[itr]-- ;
            if(indegree[itr] == 0)
                q.push(itr);
        }


    }

    if(count == numCourses)
        return true ;
    else return false ;

}