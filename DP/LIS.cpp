

// TC : O( n * logn )
// Method 1 :
class Solution {
public:
   int lengthOfLIS(vector<int>& nums) {
     int n = nums.size();
     vector<int> dp(n+1 , INT_MAX);
     dp[0] = INT_MIN ;
     for(int i = 0 ; i < n ; i++)
     {
         int ind = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
         if(dp[ind] > nums[i] && nums[i] > dp[ind-1] )
         {
             dp[ind] = nums[i];
         }
     }   
     int maxVal ;
     for(int i = n  ; i >= 0 ; i--)
     {
       if(dp[i] != INT_MAX )
       {
           maxVal = i ;
           break ;
       }
     }
     return maxVal ;
    }
};


// Method 2 : 
using namespace std;

class Solution {
public:
  int lengthOfLIS(const vector<int>& nums) {
    if (nums.empty())
      return 0;
    vector<int> tails;
    tails.reserve(nums.size());
    tails.push_back(nums.front());

    for (int i = 1; i < nums.size(); ++i) {
      const int& n = nums[i];
      auto iter = lower_bound(tails.begin(), tails.end(), n);
      if (iter == tails.end())
        tails.push_back(n);
      else if (n < *iter)
        *iter = n;
    }
    return tails.size();
  }
};


// Method 3 : 
// TC : O( n ^ 2 )

int lis( int arr[], int n ) 
{ 
	int lis[n]; 

	lis[0] = 1; 

	/* Compute optimized LIS values in bottom up manner */
	for (int i = 1; i < n; i++ ) 
	{ 
		lis[i] = 1; 
		for (int j = 0; j < i; j++ ) 
			if ( arr[i] > arr[j] && lis[i] < lis[j] + 1) 
				lis[i] = lis[j] + 1; 
	} 

	// Return maximum value in lis[] 
	return *max_element(lis, lis+n); 
} 

