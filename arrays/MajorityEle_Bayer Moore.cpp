// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int findCand(int a[] , int n)
    {
        int count = 1 , maj = 0 ;
        for(int i = 1 ; i < n ; i++)
        {
            if(a[i] == a[maj] )
                count++ ;
            else count-- ;
            if(count == 0 )
                {maj = i ;
                count = 1 ;}
        }
        return a[maj] ;
    }
    
    bool isMajority(int a[] , int n , int val)
    {
        int count = 0 ;
         for(int i = 0 ; i < n ; i++)
         {
             if(a[i] == val)
                count++;
    
         }
          if(count > n / 2)
             return true ;
         return false ;
    }
    
    int majorityElement(int a[], int size)
    {
        
       int val = findCand(a,size);
        if (isMajority(a, size, val))
            return val ;
        else
            return -1 ;
    }
};