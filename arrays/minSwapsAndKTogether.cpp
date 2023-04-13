// Input : 
// arr[ ] = {2, 7, 9, 5, 8, 7, 4} 
// K = 6 
// Output :  
// 2 

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
         int good = 0 , bad = 0  ; 
        for(int i = 0 ; i < n ; i++)
        {
            if( arr[i] <= k )
                good++;
            
        }
        for(int i = 0 ; i < good ; i++)
        {
            if(arr[i] > k )
                bad++;
        }
        
        int left = 0  , right = good , res = bad ;
        // here , right = good and not right = good-1 because there is possible that good can be 0 . 
        while(right < n )
        {
            if(arr[left] > k) bad--;
            if(arr[right] > k ) bad++;
            left++;
            right++;
            res = min(res , bad);

        }
        return res ;
    }
};