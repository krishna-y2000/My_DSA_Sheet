#include<bits/stdc++.h>
using namespace std ;


// Explanation : 
// We'll also need separate arrays to store the discovery time (disc) and 
// the lowest future node (low) for each node, as well as a time counter to use 
// with disc.

// For our recursive DFS helper (dfs), each newly-visited node should set 
// its initial value for both disc and low to the current value of time before 
// time is incremented. (Note: If we start time at 1 instead of 0, we can use 
// either disc or low as a visited array, rather than having to keep a separate 
// array for the purpose. Any non-zero value in the chosen array will then 
// represent a visited state for the given node.

// Then we recursively call dfs on each of the unvisited adjacent nodes (next) of 
// the current node (curr). If one of the possible next nodes is an earlier node
//  (disc[next] < curr[low]), then we've found a loop and we should update the
//   low value for the current node. As each layer of the recursive function 
//   backtracks, it will propagate this value of low back down the chain.

// If, after backtracking, the value of low[next] is still higher than disc[curr], then there is no looped connection, meaning that the edge between curr and next is a bridge, so we should add it to our answer array (ans).

   void dfs(int curr , int par ,int time ,vector<int> graph[] , vector<int> &vis , vector<int> &low , vector<int> &disc , vector<vector<int>> &ans )
    {
        vis[curr] = 1 ;
        disc[curr] = low[curr] = time++;
        for(auto itr : graph[curr] )
        {
            if(itr == par) continue ;
            if(!vis[itr])
            {
                dfs(itr ,curr ,time ,graph , vis ,low , disc , ans);
                low[curr] = min(low[curr] , low[itr]);
                if(low[itr] > disc[curr])  // there is a bridge
                    ans.push_back({curr, itr});
            }
            else 
                low[curr] = min(low[curr] , disc[itr] );

        }


    }
 vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> graph[n+1];
        for(auto itr : connections )
        {
            graph[itr[0]].push_back(itr[1]);
            graph[itr[1]].push_back(itr[0]);
        }
        vector<int> disc(n, -1);
        vector<int> low(n, -1); 
        vector<int> vis(n, 0); 
        vector<vector<int>> ans;
        int time = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(!vis[i] )
            {
                dfs(i ,-1,time ,graph , vis ,low , disc , ans);
            }
        }
        return ans ;
        
    }