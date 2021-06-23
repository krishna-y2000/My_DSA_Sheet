

#include<bits/stdc++.h>
using namespace std ;


struct node
{
    int data ;
    struct node* next ;

};

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        node* prev = NULL ;
        node* curr = head ;
        node* next = NULL ;
        int count = k ;
        while(count-- && curr != NULL )
        {
            next = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = next ;
        }
        if(head != NULL )
        {
            head->next = reverse(curr , k );
        }
        return prev ;
    }
};

// LinkedList: 1->2->2->4->5->6->7->8
// K = 4
// Output: 4 2 2 1 8 7 6 5 
