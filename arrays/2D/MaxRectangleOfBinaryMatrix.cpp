



class Solution{
  public:
    // to get max width for helper func we can also do right[] - left[] - 1 
    int helper( vector<int> v  )
    {
        stack<int> s ;
        v.push_back(-1);
         int i=0;
        int n = v.size() , res = 0;
        for(int i = 0 ; i < n ; i++)
        {
            while(!s.empty() && v[s.top()] > v[i])
            {
                int tpos = s.top();
                s.pop();
                int ans = v[tpos] * ( s.empty() ? i : i - s.top() - 1 );
                res = max(res , ans );
            }
            s.push(i);
        }
        return res ;
    }

    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int> v(m);
        for(int i = 0 ; i < m ; i++)
        {
           v[i] =  M[0][i] ;
        }
        int res = helper(v);
        for(int i = 1 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(M[i][j] == 1)
                    v[j]++;
                else v[j] = 0 ;
            }
            res = max( res , helper(v) );
        }
        return res ;
    }
};