

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix[0].length , col = matrix.length ;
        int begin = 0 , end = row * col - 1 ;
        while(begin <= end )
        {
            int mid = (begin + end ) / 2 ;
            int midvalue = matrix[mid / col][mid % col];
            if( mid > target )
                end = mid - 1 ;
            else if( mid < target )
                begin = mid + 1 ;
            else 
                return true ;
        }
        return false ;
    }

 int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[] ;
        for(auto it : flights)
        {
            adj[it[0]].push_back({ it[1] , it[2] });
        }
        vector<int> dist(n , INT_MAX);
        dist[src] = 0 ;
        priority_queue< tuple<int,int,int> , vector<int,int,int> , greater<tuple<int,int,int>> > pq ;
        pq.push( { 0 , src , k+1 } );
        while(!pq.empty())
        {
            auto [ currentDist , currentNode , stop ] = pq.top();
            pq.pop();
            for(auto it : adj[currentNode])
            {
                auto [nextNode , nextDist] = it;
                if( currentDist + nextDist < dist[nextNode])
                {
                    pq.emplace( {  } )
                }
            }
        }

    }


    int ans = 0 ;

    int height(Node* root)
    {
        if(!root) return 0 ;
        return 1 + max( height(root->left) , height(root->right) );
    }
    int diameter(Node* root) {
        // Your code here
        if(!root) return 0 ;
        lmax = height(root->left) ;
        rmax = height(root->right) ;
        ans = max(ans , 1 + lmax + rmax );
        diameter(root->left) ;
        diameter(root->right) ;
        return ans ;

    }

     int networkDelayTime(vector<vector<int>>& times, int n, int k)
     {
         vector<pair<int,int>> adj[n+1];
         for(auto it : times)
         {
             adj[it[0]].push_back({it[1] , it[2]});
         }
         priority_queue<pair<int,int> , vector<int ,int > , greater<pair<int,int>>> q ;
         q.push_back({0,k});
         vector<int> vis(n+1 , 0);
         vector<int> dis(n+1 , INT_MAX);
         dis[k] = 0;
         dis[0] = 0;
         int ans = 0 ;
         while(!q.empty())
         {
            
             int currentNode = q.top().second ;
             int currentDist = q.top().first ;
             vis[currentNode] = 1 ;
             q.pop();
             for(auto it : adj[currentNode])
             {
                 if(!vis[it.first])
                 {
                    int nextNode = it.first ;
                    int nextDist = it.second ;
                    if( currentDist + nextDist < dist[nextNode] )
                    {
                        dist[nextNode] = currentDist + nextDist ;
                        q.push_back({nextDist , nextNode});
                    }
                 }
             }
         }
         return ans ;
     }