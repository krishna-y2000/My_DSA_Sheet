
#include<bits/stdc++.h>
using namespace std ;


 int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
     int INF = (int) 1e6; // INF = n * maxWeight = 100 * 10^4 = 10^6
     vector<vector<int> > matrix(n , vector<int>(n ,INF) );
        for(auto &child : edges)
        {
            distMatrix[ child[0] ][ child[1] ] = child[2];  // edge between a->b with weight
            distMatrix[ child[1] ][ child[0] ] = child[2] ; 
        }
       
        for(int k = 0 ; k < n ; k++)
        {
            for( int i = 0 ;  i < n ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    distMatrix[i][j] = min(distMatrix[i][j] , distMatrix[i][k] + distMatrix[k][j] );
                }
            }
        }
        for (int i = 0; i < n; ++i)
            distMatrix[i][i] = 0;
         int count = 0 , smallest = INT_MAX , ans = -1 ;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ;j++)
            {
                if(distMatrix[i][j] <= distanceThreshold )
                    count++;
            }
            if(count <= smallest)
            {
                ans = i ;
                smallest = count ;
            }
            count = 0;
        }
        return ans ;   
    }