


class Solution {
public:
    
    string longestPalindrome(string A) {
        int start = 0;
    int length = A.size();
    if(A.size() == 0 )
        return "";
    if(A.size() == 1 )
    {
        return A ;
    }
    int maxLen = 1;
    int low = 0, high;
    
    for(int i = 0; i < length; i++){
        low = i-1;
        high = i;
        // even position
        while((low >= 0) && (high < length) && (A[low] == A[high])){
            if((high - low + 1) > maxLen){
                maxLen = high-low+1;
                start = low;
            }        
            low--;
            high++;
        }
        // odd position
        low = i-1;
        high = i+1;
        while((low >= 0) && (high < length) && A[low] == A[high]){
            if((high - low + 1) > maxLen){
                maxLen = high-low+1;
                start = low;
            }
            low--;
            high++;
        }
    }
    
    string sol = "";
    
    high = start+maxLen;
    while(start != high){
        sol = sol + A[start];
        start++;
    }
    
    return sol;
    }
};