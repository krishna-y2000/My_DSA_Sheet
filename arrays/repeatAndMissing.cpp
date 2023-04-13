#include <bits/stdc++.h>
using namespace std;

// Method 1 : Xor 
// TC : O(n)

vector < int >Solution::repeatedNumber (const vector < int >&arr) {
    /* Will hold xor of all elements and numbers from 1 to n */
    int xor1;

    /* Will have only single set bit of xor1 */
    int set_bit_no;

    int i;
    int x = 0; // missing
    int y = 0; // repeated
    int n = arr.size();

    xor1 = arr[0];

    /* Get the xor of all array elements */
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];

    /* XOR the previous result with numbers from 1 to n */
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;

    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);

    /* Now divide elements into two sets by comparing a rightmost set bit
       of xor1 with the bit at the same position in each element.
       Also, get XORs of two sets. The two XORs are the output elements.
       The following two for loops serve the purpose */

    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no)
            /* arr[i] belongs to first set */
            x = x ^ arr[i];

        else
            /* arr[i] belongs to second set */
            y = y ^ arr[i];
    }

    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            /* i belongs to first set */
            x = x ^ i;

        else
            /* i belongs to second set */
            y = y ^ i;
    }

    // NB! numbers can be swapped, maybe do a check ?
    int x_count = 0;
    for (int i=0; i<n; i++) {
        if (arr[i]==x)
            x_count++;
    }
    
    if (x_count==0)
        return {y, x};
    
    return {x, y};
}


 // Method 2 : using maths 

vector<int> Solution::repeatedNumber(const vector<int> &A) {

    long long int act_sum = 0;
    long long int act_sum_sq = 0;
    long long int exp_sum;
    long long int exp_sum_sq;
    long long int i = 0;
    
    for(i = 0; i < A.size(); i++){
        act_sum = act_sum + (long long int)A[i];
        act_sum_sq = act_sum_sq + (long long int)A[i]*A[i];
    }
    
    exp_sum = (long long int)(A.size())*(A.size()+1)/2;
    exp_sum_sq = (long long int)(A.size())*(A.size()+1)*(2*A.size()+1)/6;
    
    long long int diff_sum_sq = exp_sum_sq - act_sum_sq;
    long long int diff_sum = exp_sum - act_sum;
    
    long long int tog = diff_sum_sq/diff_sum;
    
    long long int mis = (tog + diff_sum)/2;
    long long int rep = mis - diff_sum;
    
    vector<int> sol;
    sol.push_back((int)rep);
    sol.push_back((int)mis);

    return sol;
}