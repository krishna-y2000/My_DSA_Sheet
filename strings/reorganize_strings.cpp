   #include<bits/stdc++.h>
   using namespace std ;
    
         string reorganizeString(string s) {
        string res = "";
         map<char ,int> mp ;
         priority_queue<pair<int , char>> pq ;
         for(int i = 0 ; i < s.size() ; i++)
         {
             mp[s[i]]++;
         }
         for(auto it : mp)
         {
             pq.push(make_pair(it.second , it.first) );
         }
         while(pq.size() > 1 )
         {
             auto a = pq.top();
             pq.pop();
             auto b = pq.top();
             pq.pop();
             res += a.second ;
             res += b.second ;
             a.first -= 1;
             b.first -= 1 ;
             if(a.first > 0 )
             {
                 pq.push(a);
             }
             if(b.first > 0 )
             {
                 pq.push(b);
             }

        }
          
        if(!pq.empty() )
        {
            
            if(pq.top().first > 1 )
            {
                return "" ;
            }
            else 
            {
                res += pq.top().second ;
            }
        }
        return res ;
    }
    
  