#include<bits/stdc++.h> 
using namespace std;


int main()
{
  map<int,int> mp ;
  mp[0] = -2 ;
  mp[-1] = -3 ;
  mp[1] = 2 ;
  for(auto itr = mp.begin() ; itr != mp.end() ; itr++ )
  {
    cout << itr->first << endl ;
  }
}