
#include <bits/stdc++.h>
using namespace std;

// TC : O( n*h*h ) :-> This is doubtful  

void solve(Node* root , int k  , vector<int> v  )
{

    if(!root)
        return ;
    v.push_back(root->data);
    solve(root->left , k , v);
    solve(root->right , k , v)
    int sum = 0 ;
    for(int i = v.size() - 1 ; i >= 0 ; i-- )
    {
        sum += v[i];
        if(sum == k)
        {
            for(int j = i ; j < v.size() ; j++ )
            {
                cout << v[j] << " " ;

            }
            cout << "\n" << endl ;
        }
    }
    v.pop_back();

}

void printPath(Node* root , int k)
{
    vector<int> v ;
    solve(root , k , v);
}