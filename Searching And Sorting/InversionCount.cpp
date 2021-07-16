#include<bits/stdc++.h>
using namespace std ;


long long int merge(*arr , *temp  ,long long int low , long long int mid ,long long int right  )
{
    long long int i , j , k , invCount = 0 ;
    i = left ;
    j = mid ;
    k = 0 ;
    while((i <= mid - 1 ) && j <= right )
    {
        if(arr[i] < arr[j] )
            temp[k++] = arr[i++] ;
        else 
        {
            temp[k++] = arr[j++] ;
            invCount += (mid - i );
        }
    }
    while( i <mid )
        temp[k++] = arr[i++];
    while( j <=right )
        temp[k++] = arr[j++];
    for(long long int i = left ; i < right ; i++  )
    {
        arr[i] = temp[i] ;
    }
    return invCount ;
 }

long long int  mergeSort(*arr , *temp , int left , int right )
{
    long long int mid  , invCount = 0 ;
    mid = (left + right ) / 2 ;
    invCount += mergeSort(arr , temp , left , mid   );
    invCount += mergeSort(arr , temp , mid + 1 , right);

    invCount += merge(arr , temp  , low , mid + 1 ,  right  );
    return invCount ;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long temp[N] ;
    long long int mergeSort(arr ,temp ,  0 , N - 1  );
}