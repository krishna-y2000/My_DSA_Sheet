#include<bits/stdc++.h>
using namespace std ;


// Method 1 : 
// p = wild , s = pattern
bool isMatchValue(const char *s, const char *p) {
        const char* star=NULL;
        const char* ss=s;
        while (*s){
            //advancing both pointers when (both characters match) or ('?' found in pattern)
            //note that *p will not advance beyond its length 
            if ((*p=='?')||(*p==*s)){s++;p++;continue;} 

            // * found in pattern, track index of *, only advancing pattern pointer 
            if (*p=='*'){star=p++; ss=s;continue;} 

            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //only advancing pattern pointer
            if (star){ p = star+1; s=++ss;continue;} 

           //current pattern pointer is not star, last patter pointer was not *
           //characters do not match
            return false;
        }

       //check for remaining characters in pattern
        while (*p=='*'){p++;}

        return !*p;  
    }
    bool isMatch(string s , string p )
    {
        const char* str ;
        const char* pat ;
        str = &s[0];
        pat = &p[0];
        return isMatchValue(str , pat );
    }
    


// Method 2 :  DP Solution

 bool isMatch(string s, string p) {
        int mem[s.size() + 1][p.size() + 1];
        memset(mem , -1 , sizeof mem );
        return isMatch(0,0,s,p,mem);    
    }
    bool isMatch(int i, int j, string& s, string& p,vector<vector<char>> &mem) {
        int sn = s.size();
        if(j==p.size()) return i==sn;
        if(mem[i][j]!=-1) return mem[i][j];
        if(p[j]=='*') return mem[i][j]= isMatch(i,j+1,s,p,mem) || (i<sn && isMatch(i+1,j,s,p,mem));
        if(i<sn && (p[j]=='?'|| s[i]==p[j])) return mem[i][j]=isMatch(i+1,j+1,s,p,mem);
        return mem[i][j]=0;
    }