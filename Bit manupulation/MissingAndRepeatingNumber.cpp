

// Input:[3 1 2 5 3] 

// Output:[3, 4] // [ repeating , missing ]

// A = 3, B = 4

// Method 1 : Xor method 
vector < int >Solution::repeatedNumber (const vector < int >&arr)
{
   int* res = new int[2];
    int xor1 = arr[0] , set_bit_no , x = 0 , y = 0 ;
    for(int i = 1 ; i < n ; i++ )
    {
        xor1 = xor1 ^ arr[i];
    }
     for(int i = 1 ; i <= n ; i++ )
    {
        xor1 = xor1 ^ i ;
    }
    // rightmost bit Eg : 4 => 1 0 0 . So set_bit_no = 2 (2nd index)
    set_bit_no = xor1 & ~(xor1 - 1 );
    /* Now divide elements into two sets by comparing a rightmost set bit
       of xor1 with the bit at the same position in each element.
       Also, get XORs of two sets. The two XORs are the output elements.
       The following two for loops serve the purpose */
    for(int i = 0 ; i < n ; i++)
    {
        if( arr[i] & set_bit_no )
        {
            x = x ^ arr[i] ;
        }
        else 
            y = y ^ arr[i] ;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if( i & set_bit_no )
        {
            x = x ^ i ;
        }
        else 
            y = y ^ i ;
    }
    // res => res[0] => repeating & res[1] => missing
    for(int i = 0 ; i < n ; i++)
    {
        if( arr[i] == x  )
        {
            res[0] = x ;
            res[1] = y ;
            return res ;
        }
    }
        res[0] = y ;
        res[1] = x ;
        return res ;
}

// Method 2 : Maths 

//Approach :
//  Sum(Actual) = Sum(1...N) + A - B 
//  Sum(Actual) - Sum(1...N) = A - B

// We need one more relation. How about the sum of squares?

// Sum(1^2 .. N^2) and Sum(A[0]^2 .. A[N-1]^2)?

// Sum(Actual Squares) = Sum(1^2 ... N^2) + A^2 - B^2 
// Sum(Actual Squares) - Sum(1^2 ... N^2) = (A - B)(A + B) = (Sum(Actual) - Sum(1...N))(A + B).
// Sum(Actual Squares) - Sum(1^2 ... N^2) / (A - B) = A + B 

class Solution{
public:
    int *findTwoElement(int *A, int n) {
        // code here
        int* res = new int[2];
        long long int act_sum = 0;
        long long int act_sum_sq = 0;
        long long int exp_sum;
        long long int exp_sum_sq;
        long long int i = 0;
        
        for(i = 0; i < n; i++){
            act_sum = act_sum + (long long int)A[i];
            act_sum_sq = act_sum_sq + (long long int)A[i]*A[i];
        }
        
        exp_sum = (long long int)(n)*(n+1)/2;
        exp_sum_sq = (long long int)(n)*(n+1)*(2*n+1)/6;
        
        long long int diff_sum_sq = exp_sum_sq - act_sum_sq;
        long long int diff_sum = exp_sum - act_sum;
        
        long long int tog = diff_sum_sq/diff_sum; // (A + B)
        
        long long int mis = (tog + diff_sum)/2;
        long long int rep = mis - diff_sum;
        
        res[0] = rep ;
        res[1] = mis ;
        

        return res;
    }
};