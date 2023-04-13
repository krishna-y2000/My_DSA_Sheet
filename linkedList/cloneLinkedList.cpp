#include<bits/stdc++.h>
using namespace std ;



struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};


// Method1 :
Node *copyList(Node *start) {
    // Your code here
 Node* curr = start, *temp;
 
    // insert additional node after
    // every node of original list
    while (curr)
    {
        temp = curr->next;
 
        // Inserting node
        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
 
    curr = start;
 
    // adjust the arb pointers of the
    // newly added nodes
    while (curr)
    {
        if(curr->next)
            curr->next->arb = curr->arb ?
                                 curr->arb->next : curr->arb;
 
        // move to the next newly added node by
        // skipping an original node
        curr = curr->next?curr->next->next:curr->next;
    }
 
    Node* original = start, *copy = start->next;
 
    // save the start of copied linked list
    temp = copy;
 
    // now separate the original list and copied list
    while (original && copy)
    {
        original->next =
         original->next? original->next->next : original->next;
 
        copy->next = copy->next?copy->next->next:copy->next;
        original = original->next;
        copy = copy->next;
    }
 
    return temp;
}


// Method 2 :
// Node* copyList(Node* head)
// {
//     unordered_map<Node* , Node*> mp ;
//     Node* temp = head ;
//     while(temp != NULL )
//     {
//         mp[temp] = new Node(temp->data);
//         temp = temp->next ;
//     }
//     temp = head ;
//     while(temp != NULL )
//     {
//         Node* newnode = mp[temp] ;
//         if(temp->next)
//             newnode->next = mp[temp->next];
//         if(temp->arb )
//             newnode->arb = mp[temp->next->arb];
//         temp = temp->next ;

//     }
//     Node* newhead = mp[head];

//     return newhead ;

// }
