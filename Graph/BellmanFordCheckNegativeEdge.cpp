
#include<bits/stdc++.h>
using namespace std ;

int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> dist(n+1,INT_MAX);
         dist[0] = 0;
        for(int i = 1 ; i < n ; i++ ) 
         {
             for (auto e : edges) {
                    int u = e[0], v = e[1], w = e[2];
                    if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                    }
                }
         }
         
         for (auto e : edges) {
                    int u = e[0], v = e[1], w = e[2];
                    if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                        return 1 ;  // there is negative edge
                        dist[v] = dist[u] + w;
                    }
                }
        return 0 ;
	}