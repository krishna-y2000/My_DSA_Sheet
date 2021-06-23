  #include<bits/stdc++.h>
using namespace std ;

vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    // Your Code Here
    map<string , vector<string>> mp ;
    for(int i = 0 ; i < string_list.size() ; i++ )
    {
        string temp = string_list[i];
        sort(string_list[i].begin() , string_list[i].end() );
        mp[string_list[i]].push_back(temp);
    }
    vector<vector<string> > res ;
    for(auto it = mp.begin() ; it != mp.end() ; it++ )
    {
        res.push_back(it->second );
    }
    return res ;
}