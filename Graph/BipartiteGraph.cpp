#include<bits/stdc++.h>
using namespace std ;


 bool checkColor(int node ,int c , vector<vector<int>>& graph ,vector<int> color  )
 {
     if(color[node] == c)
        return true ;

     color[node] = c ;
     for(auto it : graph[node] )
     {
         if( !checkColor(it , -c , graph , color) )
            return false ;
     }
     return true ;
 }

 bool isBipartite(vector<vector<int>>& graph) {

        vector<int> color(graph.size()  , 0 );
        for(int i = 0 ; i < graph.size() ; i++ )
        {
            if(!color[i] && !checkColor(i ,1 ,graph , color) )
                return false ;
        }
        return true ;
    }