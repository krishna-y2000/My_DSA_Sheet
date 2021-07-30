#include<bits/stdc++.h>
using namespace std ;


// check if the no is a prime
bool solve()
{
    int n ;
    cin >> n ;
    for(int i = 2  ; i * i <= n; i++ )
    {
        if( n % i == 0 )
            return false ;
    }
    return true ;
}


// print prime factor of a number
// N = (7^3) * (13^1) * (23^2)
void primeFact(int n)
{
    int count = 0;
    for(int i = 2 ; i*i <= n ; i++)
    {
        if(n%i == 0)
        {
            while(n%i == 0 )
            {
                n /= i ;
                count++ ;
            }
            cout << i << "^" << count << endl ;
        }

    }
    if(n > 1 )
    {
        cout << n << "^" << 1 << endl ;
    }

}




// Seive : Calculate prime no in a range 
int is_prime[1000001];

void sieve()
{
    int maxn = 1000000;
    for(int i = 1 ; i <= maxn ; i++  )
    {
        is_prime[i] = 0;
    }
    is_prime[0] = is_prime[1] = 0 ;
    for(int i = 2 ; i * i <= maxn ; i++ )
    {
        if(is_prime[i] )
        {
            for(int j = i*i ; j <= maxn ; j+=i )
            {
                is_prime[j] = 0 ;
            }
        }
    }
}



