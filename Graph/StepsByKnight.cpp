#include<bits/stdc++.h>
using namespace std ;


// Use BFS as DFS will give overhead 


bool isSafe(int row , int col  , int N )
{
    return x>=0 && y>=0 && x<N && y<N;
}

 int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
        int dx[]={-2,-2,-1,1,2,2,1,-1};
	    int dy[]={-1,1,2,2,1,-1,-2,-2};
       queue<vector<int>> q ;
       vector<vector<bool>> board(N , vector<bool>(N,false) )  ; 
       q.push({KnightPos[0] , KnightPos[1] , 0 } );
       board[KnightPos[0]-1][nexKnightPos[1]-1] = true ;
       while(!q.empty() )
       {
           auto node= q.front();
           q.pop();
           int a = node[0] , b = node[1]  , s = node[2] ;
           if(a == KnightPos[0] && b = KnightPos[1] )
                return node[2];
            for(int i = 0 ; i  < 8 ; i++ )
            {
                int nextRow = a + dx[i] , nextCol = b + dy[i];
                if(isSafe(nextRow , nextCol , N ) )
                {
                    board[nextRow-1][nextCol-1] = true ;
                    q.push({nextRow , nextCol , s++} )
                }
            }

       }
       return 0 ;
	}