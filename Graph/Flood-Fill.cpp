
#include<bits/stdc++.h>
using namespace std ;

// Error Code for DFS 

     bool isSafe(int i , int j ,vector<vector<int>>& image , int n )
{
    return (image[i][j] != 0 && i >= 0 && j >= 0) && (i < n && j < n ) ;
}

void  solve(int n ,int i , int j , int di[] ,  int dj[]  ,vector<vector<int>>& image ,
      vector<vector<int>>& vis, int newColor  )
    {
         if( i > n-1 && j > n-1   )
            {
                return ;
            }
        image[i][j] = newColor ;
        vis[i][j] = 1 ;
        for(int i = 0 ; i < 4 ; i++ )
        {
            int nexti = i + di[i];
            int nextj = j + dj[i];
            if(!vis[nexti][nextj] && isSafe(nexti , nextj,image , n)  )
            {
                vis[nexti][nextj] = 1  ;
                solve(n ,nexti , nextj ,di ,dj , image ,vis ,newColor );
                vis[nexti][nextj] = 0 ;
            }
        }
    }

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       if (image[sr][sc] == newColor) return image;
        int di[] = { 1 , 0 ,0 , - 1 };
        int dj[] = {0 , -1 , 1 , 0 };
        int n = image.size();
        vector<vector<int>> vis(n , vector<int>(n , 0) );
        solve(n ,sr ,sc ,di ,dj , image ,vis ,newColor );
        return image ;
    }


// Correct Solution : DFS 

// TC : (m * n )
// SC : (1) and SC : (m * n)  if visited array is used 

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> vis(image.size() , vector<int>(image[0].size() , 0 ) ) ;
        if (image[sr][sc] != newColor)
            dfs(image, sr, sc, image[sr][sc], newColor,vis);
        return image;
    }

private:
    void dfs(vector<vector<int>>& image, int i, int j, int c0, int c1 ,vector<vector<int>> vis ) 
    {
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size()
            || image[i][j] != c0 ||  vis[i][j] == 1 ) 
            return;
        image[i][j] = c1;
        vis[i][j] = 1  ;
        dfs(image, i, j - 1, c0, c1 , vis);
        dfs(image, i, j + 1, c0, c1 , vis);
        dfs(image, i - 1, j, c0, c1 , vis );
        dfs(image, i + 1, j, c0, c1 , vis);
    }