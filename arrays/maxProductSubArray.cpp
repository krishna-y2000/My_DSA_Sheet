// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    // code here
	    long minpro = arr[0] ,maxpro = arr[0] , i = 1 , maxValue = arr[0] ;
	    
	    while(i < n)
	    {
	            if(arr[i] < 0)
	            {
	                swap(minpro ,maxpro );
	            }
	            maxpro = max<long long int>(arr[i] , arr[i] * maxpro);
	            minpro = min<long long int>(arr[i] , arr[i] * minpro);
	            maxValue = max(maxpro , maxValue);
	            i++;
	    }
	    return maxValue ;
	    
	}
};


// Method 2 : Effcient algorithm

// public int maxProduct(int[] nums) {
//         int max = Integer.MIN_VALUE;    // global max
//         int maxloc = 1, minloc = 1;     // max or min end here
//         for (int num : nums) {          // negative could cause maxloc and minloc swap
//             int prod1 = maxloc * num, prod2 = minloc * num;
//             maxloc = Math.max(num, Math.max(prod1, prod2));
//             minloc = Math.min(num, Math.min(prod1, prod2));
//             max = Math.max(max, maxloc);
//         }
//         return max;
//     }