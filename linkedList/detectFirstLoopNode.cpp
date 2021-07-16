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
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
     if (slow != fast)
        return NULL;
 
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
 
    return slow;
}