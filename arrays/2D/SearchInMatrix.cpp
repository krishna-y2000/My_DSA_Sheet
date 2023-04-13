


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// Note : To get the mid value in a 2D array then. 
// we need to first find the mid index from leftmost(0) and rightmost(row * col - 1 ) index 
// and then by mid index we will get the midvalue by matrix[mid / col][mid % col]

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = matrix[0].size() , row = matrix.size() ;
        int begin = 0 , end = row * col - 1 ;
        while(begin <= end )
        {
            int mid = (begin + end ) / 2 ;
            int midvalue = matrix[mid / col][mid % col];
            if( midvalue > target )
                end = mid - 1 ;
            else if( midvalue < target )
                begin = mid + 1 ;
            else 
                return true ;
        }
        return false ;
    }
};