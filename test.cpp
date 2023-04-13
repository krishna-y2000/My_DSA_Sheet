   
   int solve( vector<vector<int>> dp , vector<int> numstemp , int left , int right  )
   {

        if(left + 1 == right)
            return 0 ;
        if(dp[left][right] != -1 )
            return dp[left][right] ;

       for(int i = left + 1 ; i < right ; i++)
       {
           int a1 = solve(dp , numstemp , left, i ) ;
           int a2 = solve(dp , numstemp , i , right ) ;
           ans = max( ans , numstemp[left] * numstemp[i] * nums[right] + a1 + a2 );
           
       }
       dp[left][right] = ans ;
   }
   
   int maxCoins(vector<int>& nums) {
       int n = nums.size();
        vector<vector<int>> dp(n + 1 , vector<int>(n+1,-1) );
        vector<int> numstemp;
        numstemp[0] = 1 ; 
        numstemp[n] = 1 ;
        int k = 1 ;
        for(int it : nums)
        {
            numstemp[k++] = it ;
        }

        return solve(dp , numstemp , 0 , n-1 );     
    }

int minSwap(int arr[], int n, int k) {
        // Complete the function
        int good = 0 , bad = 0  ; 
        for(int i = 0 ; i < n ; i++)
        {
            if( arr[i] < k )
                good++;
            
        }
        for(int i = 0 ; i < good ; i++)
        {
            if(arr[i] > k )
                bad++;
        }
        int left = 0  , right = good , res = INT_MAX;
        while( left < n && right < n )
        {
            if(arr[left] > k) bad--;
            if(arr[right] > k ) bad++;
            left++;
            right++;
            res = min(res , bad);

        }
        return res ;

    }

	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
        int i =  0 , j = m - 1 , res =  -1 ;
        while( i >= 0 & j < n )
        {
            if( arr[i][j] == 1 )
            {
                i-- ;
                res++;
            }
            else j++;

        }
       return res ;
	}

arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    int i = n-1 , j = m-1 ;
    while( i >= 0 && j >= 0 )
    {
        if( i + j + 2 == k)
            return max(arr1[i] , arr2[j]);
        if( arr1[i] >= arr2[j]  )
            i--;
        else 
            j--;
        
    }
    if( i < 0 && j >= 0)
    {
        return arr2[k-1];
    }
    else if( j < 0 && i >= 0 )
    {
        return arr1[k-1];
    }
}

bool Check( int arr[] , int mid , int M , int N )
{
    int count = 1 ;
    int sum = 0 ;
    for(int i = 0 ; i < N ; i++)
    {
        sum += arr[i] ;
        if( sum > mid  )
        {
            sum = arr[i];
            count++;
        }
        if(count > M)
                return false ;
    }
   
    return true ;
}

 int findPages(int arr[], int N, int M) 
    {
        //code here
        int sum = 0 ;
        for(int i = 0 ;  i < N ; i++)
        {
            sum += arr[i] ;
        }
        int low = arr[0] , high = sum , ans = -1 ;
        while(low <= high )
        {
            int mid = low + (high - low ) / 2 ;
            if( Check(arr , mid , M , N) )
            {
                ans = mid ;
                high = mid - 1 ; 
            }
            else 
                low = mid + 1 ;
        } 
        return ans ;
    }