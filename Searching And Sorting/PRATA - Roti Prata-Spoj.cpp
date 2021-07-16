
#include<bits/stdc++.h>
using namespace std ;

// This problem is similar to Painter's partition Problem 

bool check(int arr[] , int find , int  parn ,int chef )
{
    int parncount = 0 ;
    for( int i =  0 ; i < chef ; i++)
    {
        int time = arr[i] ;
        int j = 2 ;
        while( time <= find  )
        {
            time += j*arr[i] ;
            parncount++;
            j++;
        }
        if(parncount >= parn) 
            return true ;

    }
    
    return false ;

}


int main()
{
    int tc = 0 ; 
    cin >> tc ;
    while(tc-- > 0)
    {
        int parn , chef  , ans = 0 ;
        cin >> parn >> chef;

        int arr[chef] ;
        for(int i = 0 ; i < chef ; i++)
        {
            cin >> arr[i] ;
        }
        int low = 0  , mid = 0;
        int  high = 10000007;
        while(low <= high )
        {
            int mid = (low + high) / 2  ;
            if(check(arr , mid , parn , chef) )
            {
                ans = mid ;
                high = mid - 1 ;
            }
            else 
            {
                low = mid + 1 ;
            }
        }
        cout << ans << "\n" ;
    }
}