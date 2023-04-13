
// Input:
// N = 4
// mat[][] =          {{16, 28, 60, 64},
//                    {22, 41, 63, 91},
//                    {27, 50, 87, 93},
//                    {36, 78, 87, 94 }}
// K = 3
// Output: 27
// Explanation: 27 is the 3rd smallest element.

// Method 1 : Binary Search 
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
     int low = mat[0][0] , high  = mat[n-1][n-1];
     while(low <= high)
     {
         int mid1 = low + (high-low)/2 ;
         int count = 0 ;
         for(int i = 0 ; i < n ; i++)
         {
             int left = 0 , right = n - 1 ;
             while(left <= right)
             {
                int mid = left + (right - left) / 2 ;
                if( mat[i][mid] <= mid1  )
                {
                    left = mid + 1 ;
                }
                else 
                    right = mid - 1 ;
             }
             count += left ;
         }
         if(count >= k )
         {
             high = mid1 -1 ;
         }
         else low = mid1 + 1 ;
    
     }
     return low ;
}

// 1) Binary Search , TC - O(log(r)*n*log(n)) 
// , where r is mat[n-1][n-1] - mat[0][0]  , SC - O(1)
// 2) Heap , TC- O(n*n(logk)) , SC - O(k)

// Method 2 : Priority Queue

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
priority_queue<int>maxh;
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        maxh.push(mat[i][j]);
        if(maxh.size() > k) maxh.pop();
    }
}
return maxh.top();
}