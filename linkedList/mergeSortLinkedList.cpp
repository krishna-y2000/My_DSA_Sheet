#include<bits/stdc++.h>
using namespace std ;



struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};



class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.

//use fast/slow pointers to split the linked list in half
void FrontBackSplit( Node* source,  Node** frontref,  Node** backref){
	 Node* fast;
	 Node* slow;

		slow = source;
		fast = source ;
		while(fast != NULL && fast->next == NULL){
			  fast = fast->next->next ;
			  slow = slow->next ;
		}
	
	*frontref = source;
	*backref = slow -> next;
	slow -> next = NULL;
}

//merge two sorted linked list
 Node* sortedmerge( Node* a,  Node*b){
	 Node * result(NULL);

	if(a == NULL){
		return b;
	}
	else if(!b)
		return a;
	
	if(a -> data <= b -> data){
		result = a;
		result -> next = sortedmerge(a -> next, b);
	}
	else{
		result = b;
		result -> next = sortedmerge(a, b -> next);
	}
	return result;
}

void mergesort( Node** headref){
	 Node* head = *headref;
	 Node* a;
	 Node* b;

	//NULL or single Node
	if((head == NULL) || (head -> next == NULL))
		return;

	FrontBackSplit(*headref, &a, &b);

	mergesort(&a);
	mergesort(&b);
	*headref = sortedmerge(a,b);
}



    // Main Calling Function        
 Node* mergeSort(Node* head) {
        // your code here
         mergesort(&head);
        return head ;
    };
};