
#include<bits/stdc++.h>
using namespace std ;


class Solution{
    public:
    
     void topoSort(vector<int>gr[] , vector<int> &visited , vector<int>&ans , int src) {
        visited[src] = true;
        for(auto nodes : gr[src]) {
            if(!visited[nodes]) 
                topoSort(gr , visited,  ans , nodes);
        }
        
        ans.push_back(src);
    }
    
    string findOrder(string dict[], int N, int K) {
        vector<int> gr[K];
        
        for(int i=0 ; i< N-1 ; i++) {
            int x = dict[i].size() , y = dict[i+1].size();
            string word1 = dict[i] ;
            string word2 = dict[i+1];
            for(int j = 0 ; j < min(x,y) ; j++) {
                if(word1[j] != word2[j] ) {
                    gr[ word1[j] - 'a'].push_back( word2[j] - 'a');
                    break;
                }
            }
        }
        
        vector<int> ans;
        vector<int> visited(K , false);
        
        for(int i = 0 ; i < K ; i++) {
            if(!visited[i]) {
                topoSort(gr , visited , ans , i);
            }
        }
        
        string res = "";
        
        for(int i=K-1 ; i >= 0; i--) {
            res += (char)(ans[i]+'a');
        }
        return res;
        
    }
};