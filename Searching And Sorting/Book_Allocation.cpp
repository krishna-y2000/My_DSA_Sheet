
#include<bits/stdc++.h>
using namespace std ;

// This problem is similar to Painter's partition Problem 

bool check(int arr[] , int n , int find ,int allocate )
{
    int count = 1 ;
    int sum = 0;
    for(int i = 0 ; i < n ; i++ )
    {
        sum += arr[i] ;
        if(sum > find)
        {
            count++ ;
            sum = arr[i] ;
        }
        if(count > allocate )
            return false ;
        
    }
    return true ;
}


int findPages(int arr[], int n, int m) 
{
    //code here
    if(n < m )
        return -1 ;
    int low = -1, high = 0 , ans = -1;
    for(int i = 0 ; i < n ; i++)
    {
        low = max(low , arr[i]);
        high += arr[i] ;
    }
    while(low <= high )
    {
        int mid = low + (high-low) / 2 ;
        if(check(arr , n , mid , m ) )
            {   ans = mid ;
                high = mid - 1 ;
            
            }
        else 
            low = mid + 1 ;
    }
    return ans ;
}