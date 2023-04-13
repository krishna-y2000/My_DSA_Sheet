#include <bits/stdc++.h>
using namespace std;
//vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int row[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int col[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
bool check(int x, int y, int n, int m)
{
   return x >= 0 and y >= 0 and x < n and y < m;
}
void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int x, int y, int n, int m)
{
   if (!check(x, y, n, m) or grid[x][y] == '0' or vis[x][y] == true)
   {
       return;
   }
   vis[x][y] = true;
   for (int i = 0 ; i < 8 ; i++)
   {
       int x1 = x + row[i];
       int y1 = y + col[i];
       dfs(grid, vis, x1, y1, n, m);
   }
}
int numIslands(vector<vector<char>> &grid)
{
   int ans = 0;
   int n = grid.size();
   int m = grid[0].size();
   vector<vector<bool>> vis(n, vector<bool>(m, false));
   for (int i = 0; i < n; i++)
   {
       for (int j = 0; j < m; j++)
       {
           if (vis[i][j] == false and grid[i][j] == '1')
           {
               ans++;
               dfs(grid, vis, i, j, n, m);
           }
       }
   }
   return ans;
}
int main()
{
   vector<vector<char>> grid = {
       { 1, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
        { 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
        { 1, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
        { 0, 1, 0, 1, 0, 0, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 1, 1, 1, 0 },
        { 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 }
	   };
   cout << numIslands(grid) << endl;
   return 0;
}