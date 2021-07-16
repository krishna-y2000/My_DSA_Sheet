
// Note : Both are opposite 
// Aggresive Cows : Largest of all the minimum dist btw two cows 
// Book_Allocation : Minimum sum of pages of books among maximum pages of book allocated .  



#include<bits/stdc++.h>
using namespace std ;



int Check(vector<int> st , int n ,  int dist , int cows)
{
    int lastCow = st[0] ;
    int count = 1;
    for(int i = 1 ; i  < n  ; i++ )
    {
        if(st[i] - lastCow  >= dist )
        {
            lastCow = st[i] ;
            count++ ;
        }
    }
     if(count >= cows )
    {
        return true ;
    }
    return false ;
}

int main()
{
    int tc ;
    cin >> tc ;
    while(tc-- >0)
    {
        int stall ,cows , ans = -1;
        cin >> stall >> cows ;
        vector<int> st ;
        for(int i = 0 ; i < stall ; i++)
        {
            int val ;
            cin >> val ;
            st.push_back(val );        
        }
        sort(st.begin() , st.end() );

        int low = 1 , high = st[stall - 1] - st[0] ;
        while(low <= high  )
        {
            int mid = (low + high) >> 1 ;
            if(Check(st , st.size() ,  mid , cows ) )
            {
                ans = max(ans , mid ) ;
                low = mid + 1 ;
            } 
            else 
                high = mid - 1 ;
        }
        cout << ans << "\n" ;

    }
}