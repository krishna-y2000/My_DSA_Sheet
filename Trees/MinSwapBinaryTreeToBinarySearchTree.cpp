



// Do this problem using map : 

// v is the original inorder array of binary search
// make temp array and insert sorted v in temp i.e original given array
// mp is a map with store v value as key and index of v as value of map 
// m[v[i]] = i ; // conversion

// TC : O(n log n).

#include<bits/stdc++.h>
using namespace std;

// Inorder Traversal of Binary Tree
void inorder(int a[], std::vector<int> &v,
						int n, int index)
{
	// if index is greater or equal to vector size
	if(index >= n)
		return;
	inorder(a, v, n, 2 * index + 1);
	
	// push elements in vector
	v.push_back(a[index]);
	inorder(a, v, n, 2 * index + 2);
}

// Function to find minimum swaps to sort an array
int minSwaps(std::vector<int> &v , std::vector<int> &temp)
{
	int count = 0 ;
  unordered_map<int,int> m ;
  
  for(int i = 0 ;i < v.size();i++)
  {
  	m[v[i]] = i ;  // store the correct position of array elements
  }

  for(int i = 0; i < temp.size(); i++)   // iterating original array given using vector
    {
        
        // m[v[i]] return index of correct arrangement
        if(i == m[temp[i]]) 
            continue;
        else
        {
            // swaping of elements
            swap(temp[i] , temp[ m[temp[i]] ]);
            count++;
        }

    }

	return count;
}

// Driver code
int main()
{
	int a[] = { 5, 6, 7, 8, 9, 10, 11 };
	int n = sizeof(a) / sizeof(a[0]);
	std::vector<int> v;
	inorder(a, v, n, 0);
  vector<int> temp ;
    for(int i = 0 ; i < n ; i++)
    {
    	temp.push_back(a[i]);
    }
	cout << minSwaps(v , temp) << endl;
}