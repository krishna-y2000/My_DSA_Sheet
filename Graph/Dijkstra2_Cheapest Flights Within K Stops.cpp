

// Method 1 : Dijkstra's algo - 
//     TC  :  If we take a closer look, we can observe that the statements
//     in inner loop are executed O(V+E) times (similar to BFS).
//     So overall time complexity is O(E+V)*O(LogV) which is O((E+V)*LogV) = O(ELogV)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //vector<pair<int,int>> adj
        vector<pair<int,int>> adj[n+1];
        for(auto child : flights )
        {
            adj[child[0]].push_back({child[1] , child[2]});
        }
        vector<int> dist(n , INT_MAX);
        dist[src] = 0 ;
        priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>> , greater<tuple<int,int,int>> > pq; 
        pq.emplace(0,src,k+1);
        while(!pq.empty())
        {
            auto [currentDist,currentNode,stop] = pq.top();
            pq.pop();
            if(currentNode == dst )
                return currentDist ;
            if(stop == 0)
                continue ;
            for(auto node : adj[currentNode])
            {
                auto [nextNode , nextDist ] = node ;
                if(currentDist + nextDist < dist[nextNode] )
                {
                    pq.emplace(currentDist + nextDist ,nextNode,stop-1);
                  
                }
            }
            
        }
        return -1 ;
    }
};

// Method 2 : Bellman Ford Algo variation
// Maximum relaxation can be done for ( k + 1 ) times .
// TC: O(VE)

 int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        /* distance from source to all other nodes */
        vector<int> dist( n, INT_MAX );
        dist[src] = 0;
        
        // Run only K+1 times since we want shortest distance in K hops
        for( int i=0; i <= K; i++ ) {
            vector<int> tmp( dist );
            for( auto flight : flights ) {
                if( dist[ flight[0] ] != INT_MAX ) {
                    tmp[ flight[1] ] = min( tmp[flight[1]], dist[ flight[0] ] + flight[2] );
                }
            }
            dist = tmp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];