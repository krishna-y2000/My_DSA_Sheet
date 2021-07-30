#include<bits/stdc++.h>
using namespace std ;


class Solution {
	public:
		int checkMirrorTree(int n, int e, int A[], int B[]) {
				// code here
			map<int , stack<int> > mp ;
		 	int flag = 1 ;
			 for(int i = 0 ; i < 2*e ; i++)
			{   
					if(i%2 == 1)
					{
							mp[A[i-1]].push(A[i]);
					}
			}
			for(int i = 0 ; i < 2*e ; i++)
			{
					if(i%2 == 1 )
					{
							int val = mp[B[i-1]].top() ;
							mp[B[i-1]].pop();
							if( val == B[i])
								continue ;
							else 
							{
									flag = 0 ;
									break ;
							}
					}
			}
			return flag ;
				
		}
};