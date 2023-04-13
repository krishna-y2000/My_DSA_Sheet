#include<bits/stdc++.h>
using namespace std ;

struct Node
{
    int data ;
    struct Node* next ;
    Node() { } ;
};

Node* newNode(int data ) {
    Node* temp = new Node();
    temp->data = data ;
    temp->next = NULL;
    return temp ; 
};

Node* detectAndRemoveLoop(Node* head)
{
  
    if (head == NULL || head->next == NULL)
        return NULL;
 
    Node *slow = head, *fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while (fast && fast->next) {
        if (slow == fast)
            return true ;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false ;

        // delete the loop //
    // slow=head;
    // while(fast->next!=slow->next)
    // {
    //     fast=fast->next;
    //     slow=slow->next;
    // }

            
    // fast->next=NULL;
    // return;
}