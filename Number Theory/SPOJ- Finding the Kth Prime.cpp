#include<bits/stdc++.h>
using namespace std ;

vector<int> prime ;
bool is_prime[90000001]; // reduce time by using bool

void checkPrime()
{
    int maxn = 90000000;
    for(int i = 1 ; i <= maxn ; i++  )
    {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] =  true ;
    for(int i = 2 ; i * i <= maxn ; i++ )
    {
        if(!is_prime[i] )
        {
            for(int j = i*i ; j <= maxn ; j+=i )
            {
                is_prime[j] = true ;
            }
        }
    }

    for(int i = 2 ; i <= maxn ; i+=2 )
    {
        if(!is_prime[i] )
        {
            prime.push_back(i);
        }
    }


}


int main()
{
    int Q ;
    cin >> Q ;

    checkPrime();
    for(int i = 0 ; i < Q ; i++)
    {
       int val ; 
       cin >> val , cout << prime[val-1] << "\n" ;
    }
    
    return 0;
}