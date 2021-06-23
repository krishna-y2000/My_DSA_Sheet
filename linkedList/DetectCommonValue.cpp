#include<bits/stdc++.h>
using namespace std ;

struct Node
{
    int data ;
    struct Node* next ;
    Node(int x)
    {
        data = x ;
        next = NULL ;
    }
};

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node* n1 = head1 ;
    Node* n2 = head2 ;
    while(n1 != n2 )
    {
        n1 = n1 == NULL ? head2 : n1->next ;
        n2 = n2 == NULL ? head1 : n2->next ;
  
    }
    return n1->data ;
}

