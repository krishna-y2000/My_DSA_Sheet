#include<stdc++.h>
using namespace std ;


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set s(wordList.begin() , wordList.end() );
        queue<string> q ;
        q.push(beginWord);
        int count = 0 ;
        while(!q.empty() )
        {
            int n = q.size();
            for(int i = 0 ; i < n ; i++)
            {
                string word = q.front();
                q.pop();
                if(word == endWord )
                    return count + 1 ;
                s.erase(word);
                for(int i = 0 ; i < word.size() ; i++ )
                {
                    char c = word[i];
                    for(int j = 0 ; j < 26 ; j++ )
                    {
                        word[i] = 'a' + j ; 
                        if(s.find(word) != s.end() )
                        {
                            q.push(word); 
                        } 
                    }
                     word[i] = c;
                }
                
            }
            count++;
           
        }
        return 0 ;
    }