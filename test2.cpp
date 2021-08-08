#include<bits/stdc++.h>
using namespace std ;
     int networkDelayTime(vector<vector<int>>& times, int n, int k)
     {
         vector<pair<int,int> > adj[n+1];
         for(auto it : times)
         {
             adj[it[0]].push_back({it[1] , it[2] } );
         }
         priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int>> q ;
         vector<int> dist(n+1 , INT_MAX);
         vector<int> vis(n+1 , 0);
         dist[0] 0 ;
         q.push({k ,0 } );
         while(!q.empty())
         {
            int currentVal = q.front().first ;
            int currentDist = q.front().second ;
            for(auto child : adj[currentVal] )
            {
                if(!vis[child[0]] )
                {
                    int nextVal = child[0] ;
                    int nextDist = child[1] ;
                    if(currentDist + nextDist < dist[child[0]] )
                    {
                        dist[child[0]] = currentDist + nextDist ;
                        q.push({nextVal , nextDist});
                    }
                }
            }
            vis[currentVal] = 1 ;
         }
         int val = *max_element(dist.begin() , dist.end() );
         if(res == INT_MAX)
            return -1 ;
         return val ;
     }