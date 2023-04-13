#include<bits/stdc++.h>
using namespace std ;

// Input : ustring = "abc" ;
// Output : Now sn = { ab , "" , abc , bc , c , ac , a, b }

// Method 1 : // Choice is made by char

// i = 0  , usstring = "abc" , asf = " "
unordered_set<string> sn;
void subsequences(int i  , string ustring , string asf )
{
    if( i == ustring.size() )               
    {
        sn.insert(asf);
        return ;
    }

   subsequences(i+1,ustring, asf + ustring[i]);// Select the char 
   subsequences(i+1,ustring, asf+"");        // Does not select the c
}



// Method 2 : Choice is made by box( index of string ) of which char to choose

 // i = -1  , usstring = "abc" , asf = " "
unordered_set<string> uset ;

void printSubsequences(string str, int start, int end, string curStr = ""){
	//base case
	if (start == end) {
		return;
	}
	//print current string permutation
	uset.insert(curStr);
	for (int i = start + 1; i< end; i++) {
		curStr += str[i];
		printSubsequences(str, i, end, curStr);
		curStr = curStr.erase(curStr.size() - 1);
	}
}


