

// Audio Solution 

int median(vector<vector<int>> &matrix, int r, int c){
        // code here
         int n = matrix.size() , m = matrix[0].size() ;
        int low = matrix[0][0] , high = matrix[0][c-1];
        for(int i = 0 ; i < r ; i++ )
        {
            low = min(low , matrix[i][0]);
            high = max(high , matrix[i][c-1]);
        }
        while( low <= high  )
        {
            int mid = low + (high-low)/2 ;
            int count = 0 ; 
            for(int i = 0 ; i < r ; i++)
            {
                int ub = upper_bound( matrix[i].begin() , matrix[i].end() , mid ) - matrix[i].begin() ;
                count += ub ;
            }
            if(count <= r*c / 2)
            {
                low = mid + 1 ;
            }
            else 
                high = mid - 1;
        }   
        return low ;
    }
    }