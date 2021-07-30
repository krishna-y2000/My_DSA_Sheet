


Do this problem using map : 

v is the original inorder array of binary search
make temp array and insert sorted v in temp
mp is a map with store temp value as key and index of temp as value of map 
m[temp[i]] = i ; // conversion


Use gfg solution and change v array 

 for(int i = 0; i < v.size(); i++)
    {
        
        // m[v[i]] return index of correct arrangement
        if(i == m[v[i]]) 
            continue;
        else
        {
            // swaping of elements
            swap(v[i] , v[ m[v[i]] ]);
            count++;
        }

    }