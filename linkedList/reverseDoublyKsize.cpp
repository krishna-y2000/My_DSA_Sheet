#include<bits/stdc++.h>
using namespace std ;

struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
    
};


Node* reverseByK(Node* head , int k)
{
    if( head == NULL) return NULL ;
    Node *curr = head , *prev , *temp , *newHead ;
    int count = 0 ;
    while(curr != NULL && count < k )
    {
        newHead = curr ;
        temp = curr->prev ;
        curr->prev = curr->next ;
        curr->next = temp ;
        curr = curr->prev;
        count++;
    };
    if(count >= k )
    {
        head->next = reverseByK(curr , k);
    }
    return newHead ;
};