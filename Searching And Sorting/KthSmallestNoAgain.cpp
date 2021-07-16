#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    int test ;
    cin >> test ;
    while(test -- > 0)
    {
       int n,q;
        cin>>n>>q;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            v.push_back({x,y});
        }
        sort(v.begin() , v.end() );
        int ind = 0 ;
        for(int i = 1 ; i < v.size() ; i++ )
        {
            if(v[ind].second >= v[i].first )
            {
                v[ind].second = max(v[i].second , v[ind].second );
            }
            else 
            {
                ind++;
                v[ind] = v[i] ;
            }
        }
        while(q-- > 0)
        {
            int k ;
            cin >> k ;
             int ans=-1;
            for(int j = 0 ; j <= ind ; j++)
            {
                int diff = v[j].second - v[j].first + 1 ;
                if(diff >= k )
                {
                    ans = v[j].first + k - 1 ;
                    break ;
                }
                else 
                {
                    k -= diff ;
                }
            }
            cout << ans << "\n" ;
        }

    }
    

return 0;
}  