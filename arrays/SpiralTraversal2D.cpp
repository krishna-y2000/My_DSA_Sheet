#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int left = 0 , right = c-1 , up = 0 , down = r-1 ;
        vector<int> res ;
        while(up <= down && left <= right)
        {
                for(int i = left ; i <= right ; i++)
            {
                res.push_back(matrix[left][i]);
            }
            for(int i = up + 1 ; i <= down ; i++)
            {
                res.push_back(matrix[i][right]);
            }
            if( up != down  )
            {
                for( int i = right - 1 ; i >= left ; i-- )
                {
                    res.push_back(matrix[down][i]);
                }
            }
            if(left != right)
            {
                for(int i = down-1 ; i > up ; i--)
                {
                    res.push_back(matrix[i][left]);
                }
            }
            left++;
            right--;
            up++;
            down--;
        }
         return res ;
    }