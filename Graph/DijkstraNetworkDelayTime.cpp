
#include<bits/stdc++.h>
using namespace std ;


// Method 1 : Dijkstra's algo - 
// Commented part is solution using dist val as second argument in priority queue  
//Time Complexity of DjkA O(V^2) without min-heap but with min-priority queue it drops down to O(V + ElogV )
// TC : O(V + ElogV )

class Solution {
public:

	// struct comp{
	// 	bool operator()( pair<int,int> n1 , pair<int,int> n2  )
	// 	{
	// 		n1.second > n2.second ;
	// 	}
	// }

     int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>> adj[n+1];

		for(auto itr : times)
		{
			adj[itr[0]].push_back({itr[1] , itr[2]});
		}
		priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > q;
		//priority_queue< pair<int,int> , vector<pair<int,int>> ,comp > q;

		vector<int> dist(n+1 , INT_MAX);	
        vector<int> vis(n+1 , 0);
		q.push({0,k});
		// q.push({k ,0 });
		dist[k] = 0;
        dist[0] = 0 ;
		// queue will get the val by order of first argument 
		while(!q.empty())
		{
			int currentDist = q.top().first ;
			int prev = q.top().second ;
			// int currentDist = q.top().second ;
			// int prev = q.top().first ;
            
			q.pop();
            if(vis[prev] == 1 )
                continue ;
			for(auto itr : adj[prev])
			{
				if(!vis[itr.first] )
				{
					int nextNode = itr.first;
                    int nextDist = itr.second ;
					if(currentDist + nextDist < dist[itr.first]   )
					{
						dist[nextNode] = currentDist + nextDist ;
						q.push({ dist[itr.first] , itr.first });
						// q.push({nextNode , dist[nextNode]});
					}
				}
				
			}
			vis[prev] = 1 ;


		}
		int res = *max_element(dist.begin() , dist.end() );
        if(res == INT_MAX)
            return -1 ;
		return res ;
};
};


// Method 2 : Bellman Ford Algo variation
// TC : O( V^3 ) // here it is complete graph with no negative edge 

 int networkDelayTime(vector<vector<int>>& times, int n, int k) {
     vector<int> dist(n+1,INT_MAX);
     dist[k] = 0;
    for(int i = 0 ; i <= n - 1 ; i++ ) // N-1 in original Bellman Ford
     {
         for (auto e : times) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
     }
        int maxwait = 0;
        for (int i = 1; i <= n; i++)
            maxwait = max(maxwait, dist[i]);
        return maxwait == INT_MAX ? -1 : maxwait;
};
// TC: Explanation 
// Time complexity of Bellman-Ford algorithm is Θ(|V||E|) where |V| is 
// number of vertices and |E| is number of edges. If the graph is complete, 
// the value of |E| becomes Θ(|V|2). So overall time complexity becomes Θ(|V|3). 
// And given here is n vertices. So, the answer ends up to be Θ(n3).

