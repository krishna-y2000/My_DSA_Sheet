#include <bits/stdc++.h>

using namespace std;

int maxSubArraySum(int a[] , int n  )
{
int ans = a[0], ans_l = 0, ans_r = 0;
int sum = 0, min_sum = 0, min_pos = -1;

for (int r = 0; r < n; ++r) {
    sum += a[r];
    int cur = sum - min_sum;
    if (cur > ans) {
        ans = cur;
        ans_l = min_pos + 1;
        ans_r = r;
    }
    if (sum < min_sum) {
        min_sum = sum;
        min_pos = r;
    }
}
return ans ;
}

int main()
{
   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
   cout << "Maximum contiguous sum is " << max_sum;
   return 0;
   
}



// Method 2 : 
// int ans = a[0], ans_l = 0, ans_r = 0;
// int sum = 0, minus_pos = -1;

// for (int r = 0; r < n; ++r) {
//     sum += a[r];
//     if (sum > ans) {
//         ans = sum;
//         ans_l = minus_pos + 1;
//         ans_r = r;
//     }
//     if (sum < 0) {
//         sum = 0;
//         minus_pos = r;
//     }
// }