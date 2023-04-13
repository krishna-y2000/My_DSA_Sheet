#include <bits/stdc++.h>

using namespace std;

    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int , int> mp ;
        int count = 0 ; 
        for(int i = 0 ; i < n ; i++){
            int b = k - arr[i];
            if(mp[b])
            {
                count += mp[b];
            }
            mp[arr[i]]++;
        }
        return count ;
    }
     if(outofplace == -1) {
            // check if current entry is out-of-place
            if (((arr[index] >= 0) && (!(index & 0x01)))
                || ((arr[index] < 0) && (index & 0x01))) {
                outofplace = index;
            }
        }
    