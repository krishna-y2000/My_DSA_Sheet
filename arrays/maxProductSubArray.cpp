// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Input: arr[] = {6, -3, -10, 0, 2}
// Output:   180  // The subarray is {6, -3, -10}


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


// Method 3 : Prefix and Suffix

// long long maxProduct(int *arr, int n) {

// 	long long suff = 1 , pre = 1 , maxval = INT_MIN ; 
//     	for(int i= 0 ; i < n ; i++)
//     	{
//     		suff *= arr[i] ;
//     		pre *= arr[n-i-1];
//     		maxval = max(maxval , max(suff , pre));
//     		if(suff == 0) suff = 1 ;
//     		if(pre == 0) pre = 1 ;
//     	}
//     	return maxval ;
// }
