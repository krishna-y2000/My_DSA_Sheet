
#include<bits/stdc++.h>
using namespace std ;




void solve(int row, vector<string> &board, vector<vector<string>> &ans, 
               vector<int> &cols, 
               vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
        {
            if(n == row )
            {
                ans.push_back(board );
                return ;
            }

            for(int col =  0; col < n ; col++ )
            {
                if(cols[col] == 0 && lowerDiagonal[col + row ] == 0 && upperDiagonal[row - col + n - 1] == 0 )
                {
                    board[[row]][col] = 'Q' ;
                    cols[col] = 1 ;
                    lowerDiagonal[col + row ] = 1 ;
                    upperDiagonal[row - col + n - 1] = 1 ;
                    solve(row + 1  , board , ans , cols , upperDiagonal , lowerDiagonal , n  );
                    cols[col] = 0 ;
                    board[row][col] = '.' ;
                    lowerDiagonal[col + row ] = 0 ;
                    upperDiagonal[row - col + n - 1] = 0 ;
                }   
            }
        }

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans ;
        vector<string> board(n); 
        string s(n , '.' );
        for(int i = 0 ; i < n ; i++)
        {
            board[i] = s ;
        }
        vector<int> cols(n , 0 )  , upperDiagonal(2*n - 1 , 0 ) , lowerDiagonal(2*n - 1 , 0 );
        solve(0 , board , ans , cols , upperDiagonal , lowerDiagonal , n  );
        return ans ;

    }
};